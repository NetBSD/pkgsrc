$NetBSD: patch-.._vendor_sys-info-0.7.0_lib.rs,v 1.1 2021/03/11 19:25:04 fox Exp $

Adds NetBSD support for sys-info crate.

This patch has been upstreamed. And will be removed once it is merged.

Upstream PR: https://github.com/FillZpp/sys-info-rs/pull/91

--- ../vendor/sys-info-0.7.0/lib.rs.orig	2021-03-10 06:17:13.843206667 +0000
+++ ../vendor/sys-info-0.7.0/lib.rs
@@ -11,16 +11,16 @@ use std::ffi;
 use std::fmt;
 use std::io::{self, Read};
 use std::fs::File;
-#[cfg(any(target_os = "windows", target_os = "macos", target_os = "freebsd"))]
+#[cfg(any(target_os = "windows", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
 use std::os::raw::c_char;
 #[cfg(not(any(target_os = "windows", target_os = "linux")))]
 use std::os::raw::{c_int, c_double};
 
-#[cfg(any(target_os = "macos", target_os = "freebsd"))]
+#[cfg(any(target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
 use libc::sysctl;
-#[cfg(any(target_os = "macos", target_os = "freebsd"))]
+#[cfg(any(target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
 use std::mem::size_of_val;
-#[cfg(any(target_os = "macos", target_os = "freebsd"))]
+#[cfg(any(target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
 use std::ptr::null_mut;
 #[cfg(not(target_os = "windows"))]
 use libc::timeval;
@@ -32,9 +32,9 @@ use std::collections::HashMap;
 #[cfg(any(target_os = "solaris", target_os = "illumos"))]
 mod kstat;
 
-#[cfg(any(target_os = "macos", target_os="freebsd"))]
+#[cfg(any(target_os = "macos", target_os="freebsd", target_os = "netbsd"))]
 static OS_CTL_KERN: libc::c_int = 1;
-#[cfg(any(target_os = "macos", target_os="freebsd"))]
+#[cfg(any(target_os = "macos", target_os="freebsd", target_os = "netbsd"))]
 static OS_KERN_BOOTTIME: libc::c_int = 21;
 
 /// System load average value.
@@ -172,28 +172,32 @@ impl From<Box<dyn std::error::Error>> fo
 extern "C" {
     #[cfg(any(target_os = "macos", target_os = "windows"))]
     fn get_os_type() -> *const i8;
-    #[cfg(any(target_os = "macos", target_os = "windows", target_os = "freebsd"))]
+    #[cfg(any(target_os = "macos", target_os = "windows", target_os = "freebsd", target_os = "netbsd"))]
     fn get_os_release() -> *const i8;
 
-    #[cfg(all(not(any(target_os = "solaris", target_os = "illumos", target_os = "freebsd")), any(unix, windows)))]
+    #[cfg(all(not(any(target_os = "solaris", target_os = "illumos", target_os = "freebsd", target_os = "netbsd")), any(unix, windows)))]
     fn get_cpu_num() -> u32;
-    #[cfg(any(target_os = "macos", target_os = "windows", target_os = "freebsd"))]
+    #[cfg(any(target_os = "macos", target_os = "windows", target_os = "freebsd", target_os = "netbsd"))]
     fn get_cpu_speed() -> u64;
 
     #[cfg(target_os = "windows")]
     fn get_loadavg() -> LoadAvg;
-    #[cfg(any(target_os = "macos", target_os = "windows", target_os = "freebsd"))]
+    #[cfg(any(target_os = "macos", target_os = "windows", target_os = "freebsd", target_os = "netbsd"))]
     fn get_proc_total() -> u64;
 
     #[cfg(any(target_os = "macos", target_os = "windows"))]
     fn get_mem_info() -> MemInfo;
     #[cfg(target_os = "freebsd")]
     fn get_mem_info_freebsd(mi: &mut MemInfo) ->i32;
-
+    #[cfg(target_os = "netbsd")]
+    fn get_mem_info(mi: &mut MemInfo) ->i32;
+    
     #[cfg(any(target_os = "linux", target_os = "macos", target_os = "windows"))]
     fn get_disk_info() -> DiskInfo;
     #[cfg(target_os = "freebsd")]
     fn get_disk_info_freebsd(di: &mut DiskInfo) -> i32;
+    #[cfg(target_os = "netbsd")]
+    fn get_disk_info(di: &mut DiskInfo) -> i32;    
 }
 
 
@@ -225,7 +229,11 @@ pub fn os_type() -> Result<String, Error
     {
         Ok("freebsd".to_string())
     }
-    #[cfg(not(any(target_os = "linux", target_os = "macos", target_os = "windows", target_os = "solaris", target_os = "illumos", target_os = "freebsd")))]
+    #[cfg(target_os = "netbsd")]
+    {
+        Ok("netbsd".to_string())
+    }    
+    #[cfg(not(any(target_os = "linux", target_os = "macos", target_os = "windows", target_os = "solaris", target_os = "illumos", target_os = "freebsd", target_os = "netbsd")))]
     {
         Err(Error::UnsupportedSystem)
     }
@@ -242,7 +250,7 @@ pub fn os_release() -> Result<String, Er
         s.pop(); // pop '\n'
         Ok(s)
     }
-    #[cfg(any(target_os = "macos", target_os = "windows", target_os = "freebsd"))]
+    #[cfg(any(target_os = "macos", target_os = "windows", target_os = "freebsd", target_os = "netbsd"))]
     {
         unsafe {
 	    let rp = get_os_release() as *const c_char;
@@ -270,7 +278,7 @@ pub fn os_release() -> Result<String, Er
             Some(release) => Ok(release),
         }
     }
-    #[cfg(not(any(target_os = "linux", target_os = "macos", target_os = "windows", target_os = "solaris", target_os = "illumos", target_os = "freebsd")))]
+    #[cfg(not(any(target_os = "linux", target_os = "macos", target_os = "windows", target_os = "solaris", target_os = "illumos", target_os = "freebsd", target_os = "netbsd")))]
     {
         Err(Error::UnsupportedSystem)
     }
@@ -342,7 +350,7 @@ fn parse_line_for_linux_os_release(l: St
 ///
 /// Notice, it returns the logical cpu quantity.
 pub fn cpu_num() -> Result<u32, Error> {
-    #[cfg(any(target_os = "solaris", target_os = "illumos", target_os = "freebsd"))]
+    #[cfg(any(target_os = "solaris", target_os = "illumos", target_os = "freebsd", target_os = "netbsd"))]
     {
         let ret = unsafe { libc::sysconf(libc::_SC_NPROCESSORS_ONLN) };
         if ret < 1 || ret > std::u32::MAX as i64 {
@@ -351,7 +359,7 @@ pub fn cpu_num() -> Result<u32, Error> {
             Ok(ret as u32)
         }
     }
-    #[cfg(all(not(any(target_os = "solaris", target_os = "illumos", target_os="freebsd")), any(unix, windows)))]
+    #[cfg(all(not(any(target_os = "solaris", target_os = "illumos", target_os="freebsd", target_os = "netbsd")), any(unix, windows)))]
     {
         unsafe { Ok(get_cpu_num()) }
     }
@@ -391,7 +399,7 @@ pub fn cpu_speed() -> Result<u64, Error>
     {
         unsafe { Ok(get_cpu_speed()) }
     }
-    #[cfg(any(target_os = "freebsd"))]
+    #[cfg(any(target_os = "freebsd", target_os = "netbsd"))]
     {
 	let res: u64 = unsafe { get_cpu_speed() };
 	match res {
@@ -399,7 +407,7 @@ pub fn cpu_speed() -> Result<u64, Error>
 	    _ => Ok(res),
 	}
     }
-    #[cfg(not(any(target_os = "solaris", target_os = "illumos", target_os = "linux", target_os = "macos", target_os = "windows", target_os = "freebsd")))]
+    #[cfg(not(any(target_os = "solaris", target_os = "illumos", target_os = "linux", target_os = "macos", target_os = "windows", target_os = "freebsd", target_os = "netbsd")))]
     {
         Err(Error::UnsupportedSystem)
     }
@@ -423,7 +431,7 @@ pub fn loadavg() -> Result<LoadAvg, Erro
             fifteen: loads[2],
         })
     }
-    #[cfg(any(target_os = "solaris", target_os = "illumos", target_os = "macos", target_os = "freebsd"))]
+    #[cfg(any(target_os = "solaris", target_os = "illumos", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
     {
         let mut l: [c_double; 3] = [0f64; 3];
         if unsafe { libc::getloadavg(l.as_mut_ptr(), l.len() as c_int) } < 3 {
@@ -440,7 +448,7 @@ pub fn loadavg() -> Result<LoadAvg, Erro
     {
         Ok(unsafe { get_loadavg() })
     }
-    #[cfg(not(any(target_os = "linux", target_os = "solaris", target_os = "illumos", target_os = "macos", target_os = "windows", target_os = "freebsd")))]
+    #[cfg(not(any(target_os = "linux", target_os = "solaris", target_os = "illumos", target_os = "macos", target_os = "windows", target_os = "freebsd", target_os = "netbsd")))]
     {
         Err(Error::UnsupportedSystem)
     }
@@ -466,7 +474,7 @@ pub fn proc_total() -> Result<u64, Error
     {
         Ok(unsafe { get_proc_total() })
     }
-    #[cfg(target_os = "freebsd")]
+    #[cfg(any(target_os = "freebsd", target_os = "netbsd"))]
     {
 	let res: u64 = unsafe { get_proc_total() };
 	match res {
@@ -474,7 +482,7 @@ pub fn proc_total() -> Result<u64, Error
 	    _ => Ok(res),
 	}
     }
-    #[cfg(not(any(target_os = "linux", target_os = "solaris", target_os = "illumos", target_os = "macos", target_os = "windows", target_os = "freebsd")))]
+    #[cfg(not(any(target_os = "linux", target_os = "solaris", target_os = "illumos", target_os = "macos", target_os = "windows", target_os = "freebsd", target_os = "netbsd")))]
     {
         Err(Error::UnsupportedSystem)
     }
@@ -559,7 +567,18 @@ pub fn mem_info() -> Result<MemInfo, Err
 	    _ => Err(Error::Unknown),
 	}
     }
-    #[cfg(not(any(target_os = "linux", target_os = "solaris", target_os = "illumos", target_os = "macos", target_os = "windows", target_os = "freebsd")))]
+    #[cfg(target_os = "netbsd")]
+    {
+	let mut mi:MemInfo = MemInfo{total: 0, free: 0, avail: 0, buffers: 0,
+				     cached: 0, swap_total: 0, swap_free: 0};
+	let res: i32 = unsafe { get_mem_info(&mut mi) };
+	match res {
+	    -1 => Err(Error::IO(io::Error::last_os_error())),
+	    0 => Ok(mi),
+	    _ => Err(Error::Unknown),
+	}
+    }    
+    #[cfg(not(any(target_os = "linux", target_os = "solaris", target_os = "illumos", target_os = "macos", target_os = "windows", target_os = "freebsd", target_os = "netbsd")))]
     {
         Err(Error::UnsupportedSystem)
     }
@@ -583,7 +602,17 @@ pub fn disk_info() -> Result<DiskInfo, E
 	    _ => Err(Error::Unknown),
 	}
     }
-    #[cfg(not(any(target_os = "linux", target_os = "macos", target_os = "windows", target_os = "freebsd")))]
+    #[cfg(target_os = "netbsd")]
+    {
+	let mut di:DiskInfo = DiskInfo{total: 0, free: 0};
+	let res: i32 = unsafe { get_disk_info(&mut di) };
+	match res {
+	    -1 => Err(Error::IO(io::Error::last_os_error())),
+	    0 => Ok(di),
+	    _ => Err(Error::Unknown),
+	}
+    }    
+    #[cfg(not(any(target_os = "linux", target_os = "macos", target_os = "windows", target_os = "freebsd", target_os = "netbsd")))]
     {
         Err(Error::UnsupportedSystem)
     }
@@ -633,7 +662,7 @@ pub fn boottime() -> Result<timeval, Err
         bt.tv_usec = secs[1] as libc::suseconds_t;
 	Ok(bt)
     }
-    #[cfg(any(target_os = "macos", target_os="freebsd"))]
+    #[cfg(any(target_os = "macos", target_os="freebsd", target_os="netbsd"))]
     {
         let mut mib = [OS_CTL_KERN, OS_KERN_BOOTTIME];
         let mut size: libc::size_t = size_of_val(&bt) as libc::size_t;
