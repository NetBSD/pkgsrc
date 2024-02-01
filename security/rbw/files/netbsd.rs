use crate::{Error, Protection, Region, Result};
use libc::{c_char, c_int, c_void, free, getpid, pid_t};
use std::io;

pub struct QueryIter {
  vmmap: *mut kinfo_vmentry,
  vmmap_len: usize,
  vmmap_index: usize,
  upper_bound: usize,
}

impl QueryIter {
  pub fn new(origin: *const (), size: usize) -> Result<QueryIter> {
    let mut vmmap_len = 0;
    let vmmap = unsafe { kinfo_getvmmap(getpid(), &mut vmmap_len) };

    if vmmap.is_null() {
      return Err(Error::SystemCall(io::Error::last_os_error()));
    }

    Ok(QueryIter {
      vmmap,
      vmmap_len: vmmap_len as usize,
      vmmap_index: 0,
      upper_bound: (origin as usize).saturating_add(size),
    })
  }

  pub fn upper_bound(&self) -> usize {
    self.upper_bound
  }
}

impl Iterator for QueryIter {
  type Item = Result<Region>;

  fn next(&mut self) -> Option<Self::Item> {
    if self.vmmap_index >= self.vmmap_len {
      return None;
    }

    let offset = self.vmmap_index * std::mem::size_of::<kinfo_vmentry>();
    let entry = unsafe { &*((self.vmmap as *const c_void).add(offset) as *const kinfo_vmentry) };

    self.vmmap_index += 1;
    Some(Ok(Region {
      base: entry.kve_start as *const _,
      protection: Protection::from_native(entry.kve_protection as i32),
      shared: (entry.kve_flags & KVME_FLAG_COW as u32) == 0,
      size: (entry.kve_end - entry.kve_start) as _,
      ..Default::default()
    }))
  }
}

impl Drop for QueryIter {
  fn drop(&mut self) {
    unsafe { free(self.vmmap as *mut c_void) }
  }
}

impl Protection {
  fn from_native(protection: c_int) -> Self {
    const MAPPINGS: &[(c_int, Protection)] = &[
      (KVME_PROT_READ, Protection::READ),
      (KVME_PROT_WRITE, Protection::WRITE),
      (KVME_PROT_EXEC, Protection::EXECUTE),
    ];

    MAPPINGS
      .iter()
      .filter(|(flag, _)| protection & *flag == *flag)
      .fold(Protection::NONE, |acc, (_, prot)| acc | *prot)
  }
}

// These defintions come from <sys/sysctl.h>, describing data returned by the
// `kinfo_getvmmap` system call.
#[repr(C)]
struct kinfo_vmentry {
  kve_start: u64,
  kve_end: u64,
  kve_offset: u64,
  kve_type: u32,
  kve_flags: u32,
  kve_count: u32,
  kve_wired_count: u32,
  kve_advice: u32,
  kve_attributes: u32,
  kve_protection: u32,
  kve_max_protection: u32,
  kve_ref_count: u32,
  kve_inheritance: u32,
  kve_vn_fileid: u64,
  kve_vn_size: u64,
  kve_vn_fsid: u64,
  kve_vn_rdev: u64,
  kve_vn_type: u32,
  kve_vn_mode: u32,
  kve_path: [[c_char; 32]; 32],
}

const KVME_FLAG_COW: c_int = 0x00000001;
const KVME_PROT_READ: c_int = 0x00000001;
const KVME_PROT_WRITE: c_int = 0x00000002;
const KVME_PROT_EXEC: c_int = 0x00000004;

#[link(name = "util")]
extern "C" {
  fn kinfo_getvmmap(pid: pid_t, cntp: *mut c_int) -> *mut kinfo_vmentry;
}

#[cfg(test)]
mod tests {
  use super::*;

  #[test]
  fn protection_flags_are_mapped_from_native() {
    let rw = KVME_PROT_READ | KVME_PROT_WRITE;
    let rwx = rw | KVME_PROT_EXEC;

    assert_eq!(Protection::from_native(0), Protection::NONE);
    assert_eq!(Protection::from_native(KVME_PROT_READ), Protection::READ);
    assert_eq!(Protection::from_native(rw), Protection::READ_WRITE);
    assert_eq!(Protection::from_native(rwx), Protection::READ_WRITE_EXECUTE);
  }
}
