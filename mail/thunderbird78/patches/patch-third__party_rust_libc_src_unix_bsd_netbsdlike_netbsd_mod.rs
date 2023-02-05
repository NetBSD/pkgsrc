$NetBSD: patch-third__party_rust_libc_src_unix_bsd_netbsdlike_netbsd_mod.rs,v 1.1 2023/02/05 08:32:24 he Exp $

--- third_party/rust/libc/src/unix/bsd/netbsdlike/netbsd/mod.rs.orig	2020-08-28 21:33:54.000000000 +0000
+++ third_party/rust/libc/src/unix/bsd/netbsdlike/netbsd/mod.rs
@@ -1,6 +1,7 @@
 pub type clock_t = ::c_uint;
 pub type suseconds_t = ::c_int;
 pub type dev_t = u64;
+pub type key_t = c_long;
 pub type blksize_t = i32;
 pub type fsblkcnt_t = u64;
 pub type fsfilcnt_t = u64;
@@ -282,6 +283,30 @@ s_no_extra_traits! {
     }
 
     #[repr(packed)]
+    pub struct ipc_perm {
+        pub cuid: ::uid_t,
+        pub cgid: ::gid_t,
+        pub uid: ::uid_t,
+        pub gid: ::gid_t,
+        pub mode: ::mode_t,
+        pub seq: ::c_ushort,
+        pub key: ::key_t,
+    }
+
+    #[repr(packed)]
+    pub struct shmid_ds {
+        pub shm_perm: ::ipc_perm,
+        pub shm_segsz: ::size_t,
+        pub shm_lpid: ::pid_t,
+        pub shm_cpid: ::pid_t,
+        pub shm_nattch: ::c_short,
+        pub shm_atime: ::time_t,
+        pub shm_dtime: ::time_t,
+        pub shm_ctime: ::time_t,
+        pub shm_internal: *mut ::c_void,
+    }
+
+    #[repr(packed)]
     pub struct in_addr {
         pub s_addr: ::in_addr_t,
     }
@@ -907,11 +932,18 @@ pub const SCM_CREDS: ::c_int = 0x10;
 
 pub const O_DSYNC : ::c_int = 0x10000;
 
+pub const MAP_ANONYMOUS : ::c_int = 0x1000;
 pub const MAP_RENAME : ::c_int = 0x20;
 pub const MAP_NORESERVE : ::c_int = 0x40;
 pub const MAP_HASSEMAPHORE : ::c_int = 0x200;
 pub const MAP_WIRED: ::c_int = 0x800;
 
+pub const IPC_PRIVATE: ::key_t = 0;
+pub const IPC_CREAT: ::c_int = 0x1000;
+pub const IPC_EXCL: ::c_int = 0x2000;
+pub const IPC_NOWAIT: ::c_int = 0x4000;
+pub const IPC_RMID: ::c_int = 0;
+
 pub const DCCP_TYPE_REQUEST: ::c_int = 0;
 pub const DCCP_TYPE_RESPONSE: ::c_int = 1;
 pub const DCCP_TYPE_DATA: ::c_int = 2;
@@ -1583,6 +1615,13 @@ extern {
                   pid: ::pid_t,
                   addr: *mut ::c_void,
                   data: ::c_int) -> ::c_int;
+    pub fn shmget(key: ::key_t, size: ::size_t, shmflg: ::c_int) -> ::c_int;
+    pub fn shmat(shmid: ::c_int, shmaddr: *const ::c_void,
+        shmflg: ::c_int) -> *mut ::c_void;
+    pub fn shmdt(shmaddr: *const ::c_void) -> ::c_int;
+    #[cfg_attr(target_os = "netbsd", link_name = "__shmctl50")]
+    pub fn shmctl(shmid: ::c_int, cmd: ::c_int,
+        buf: *mut ::shmid_ds) -> ::c_int;
     pub fn pthread_setname_np(t: ::pthread_t,
                               name: *const ::c_char,
                               arg: *mut ::c_void) -> ::c_int;
