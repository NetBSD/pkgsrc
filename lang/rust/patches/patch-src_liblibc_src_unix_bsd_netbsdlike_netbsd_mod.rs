$NetBSD: patch-src_liblibc_src_unix_bsd_netbsdlike_netbsd_mod.rs,v 1.1 2018/10/31 16:30:44 martin Exp $

Temporary patch untill 

	https://github.com/rust-lang/libc/pull/1108

gets merged upstream.
Fixes mutex/pthread types for some NetBSD architectures.

--- src/liblibc/src/unix/bsd/netbsdlike/netbsd/mod.rs.orig	2018-10-24 22:01:28.000000000 +0200
+++ src/liblibc/src/unix/bsd/netbsdlike/netbsd/mod.rs	2018-10-30 13:26:45.473542210 +0100
@@ -9,6 +9,21 @@ pub type fsfilcnt_t = ::uint64_t;
 pub type idtype_t = ::c_int;
 pub type mqd_t = ::c_int;
 
+cfg_if! {
+    if #[cfg(any(target_arch = "aarch64",
+                 target_arch = "sparc", target_arch = "sparc64",
+                 target_arch = "x86", target_arch = "x86_64"))] {
+        type __cpu_simple_lock_t = ::c_uchar;
+    } else if #[cfg(any(target_arch = "arm", target_arch = "powerpc",
+                        target_arch = "powerpc64"))] {
+        type __cpu_simple_lock_t = ::c_int;
+    } else if #[cfg(any(target_arch = "mips", target_arch = "mips64"))] {
+        type __cpu_simple_lock_t = ::c_uint;
+    } else {
+        // Unknown target_arch
+    }
+}
+
 s! {
     pub struct aiocb {
         pub aio_offset: ::off_t,
@@ -160,9 +175,13 @@ s! {
 
     pub struct pthread_mutex_t {
         ptm_magic: ::c_uint,
-        ptm_errorcheck: ::c_uchar,
+        ptm_errorcheck: __cpu_simple_lock_t,
+        #[cfg(any(target_arch = "sparc", target_arch = "sparc64",
+                 target_arch = "x86", target_arch = "x86_64"))]
         ptm_pad1: [u8; 3],
-        ptm_interlock: ::c_uchar,
+        ptm_interlock: __cpu_simple_lock_t,
+        #[cfg(any(target_arch = "sparc", target_arch = "sparc64",
+                 target_arch = "x86", target_arch = "x86_64"))]
         ptm_pad2: [u8; 3],
         ptm_owner: ::pthread_t,
         ptm_waiters: *mut u8,
@@ -182,7 +201,7 @@ s! {
 
     pub struct pthread_cond_t {
         ptc_magic: ::c_uint,
-        ptc_lock: ::c_uchar,
+        ptc_lock: __cpu_simple_lock_t,
         ptc_waiters_first: *mut u8,
         ptc_waiters_last: *mut u8,
         ptc_mutex: *mut ::pthread_mutex_t,
@@ -196,7 +215,7 @@ s! {
 
     pub struct pthread_rwlock_t {
         ptr_magic: ::c_uint,
-        ptr_interlock: ::c_uchar,
+        ptr_interlock: __cpu_simple_lock_t,
         ptr_rblocked_first: *mut u8,
         ptr_rblocked_last: *mut u8,
         ptr_wblocked_first: *mut u8,
@@ -692,17 +711,33 @@ pub const FD_SETSIZE: usize = 0x100;
 
 pub const ST_NOSUID: ::c_ulong = 8;
 
-pub const PTHREAD_MUTEX_INITIALIZER: pthread_mutex_t = pthread_mutex_t {
-    ptm_magic: 0x33330003,
-    ptm_errorcheck: 0,
-    ptm_interlock: 0,
-    ptm_waiters: 0 as *mut _,
-    ptm_owner: 0,
-    ptm_pad1: [0; 3],
-    ptm_pad2: [0; 3],
-    ptm_recursed: 0,
-    ptm_spare2: 0 as *mut _,
-};
+cfg_if! {
+    if #[cfg(any(target_arch = "sparc", target_arch = "sparc64",
+                 target_arch = "x86", target_arch = "x86_64"))] {
+        pub const PTHREAD_MUTEX_INITIALIZER: pthread_mutex_t = pthread_mutex_t {
+            ptm_magic: 0x33330003,
+            ptm_errorcheck: 0,
+            ptm_interlock: 0,
+            ptm_waiters: 0 as *mut _,
+            ptm_owner: 0,
+            ptm_pad1: [0; 3],
+            ptm_pad2: [0; 3],
+            ptm_recursed: 0,
+            ptm_spare2: 0 as *mut _,
+        };
+    } else {
+        pub const PTHREAD_MUTEX_INITIALIZER: pthread_mutex_t = pthread_mutex_t {
+            ptm_magic: 0x33330003,
+            ptm_errorcheck: 0,
+            ptm_interlock: 0,
+            ptm_waiters: 0 as *mut _,
+            ptm_owner: 0,
+            ptm_recursed: 0,
+            ptm_spare2: 0 as *mut _,
+        };
+    }
+}
+
 pub const PTHREAD_COND_INITIALIZER: pthread_cond_t = pthread_cond_t {
     ptc_magic: 0x55550005,
     ptc_lock: 0,
@@ -969,6 +1004,15 @@ pub const SOCK_NONBLOCK: ::c_int = 0x200
 
 pub const SIGSTKSZ : ::size_t = 40960;
 
+pub const PT_DUMPCORE: ::c_int = 12;
+pub const PT_LWPINFO: ::c_int = 13;
+pub const PT_SYSCALL: ::c_int = 14;
+pub const PT_SYSCALLEMU: ::c_int = 15;
+pub const PT_SET_EVENT_MASK: ::c_int = 16;
+pub const PT_GET_EVENT_MASK: ::c_int = 17;
+pub const PT_GET_PROCESS_STATE: ::c_int = 18;
+pub const PT_FIRSTMACH: ::c_int = 32;
+
 // dirfd() is a macro on netbsd to access
 // the first field of the struct where dirp points to:
 // http://cvsweb.netbsd.org/bsdweb.cgi/src/include/dirent.h?rev=1.36
@@ -1097,6 +1141,8 @@ extern {
                      base: ::locale_t) -> ::locale_t;
     #[link_name = "__settimeofday50"]
     pub fn settimeofday(tv: *const ::timeval, tz: *const ::c_void) -> ::c_int;
+
+    pub fn dup3(src: ::c_int, dst: ::c_int, flags: ::c_int) -> ::c_int;
 }
 
 #[link(name = "util")]
