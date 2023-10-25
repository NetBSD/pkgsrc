$NetBSD: patch-library_std_src_sys_unix_thread__parking_netbsd.rs,v 1.3 2023/10/25 05:50:43 pin Exp $

Try to cast to make this build, to avoid

error[E0277]: the trait bound `i32: core::convert::From<u32>` is not satisfied
  --> library/std/src/sys/unix/thread_parking/netbsd.rs:37:37
   |
37 |         tv_nsec: dur.subsec_nanos().into(),
   |                                     ^^^^ the trait `core::convert::From<u32>` is not implemented for `i32`
   |
   = help: the following other types implement trait `core::convert::From<T>`:
             <i32 as core::convert::From<NonZeroI32>>
             <i32 as core::convert::From<bool>>
             <i32 as core::convert::From<i16>>
             <i32 as core::convert::From<i8>>
             <i32 as core::convert::From<u16>>
             <i32 as core::convert::From<u8>>
   = note: required for `u32` to implement `core::convert::Into<i32>`

For more information about this error, try `rustc --explain E0277`.

This to un-break the 32-bit ports ... again.

--- library/std/src/sys/unix/thread_parking/netbsd.rs.orig	2023-03-06 15:58:58.000000000 +0000
+++ library/std/src/sys/unix/thread_parking/netbsd.rs
@@ -34,7 +34,7 @@ pub fn park_timeout(dur: Duration, hint:
         // Saturate so that the operation will definitely time out
         // (even if it is after the heat death of the universe).
         tv_sec: dur.as_secs().try_into().ok().unwrap_or(time_t::MAX),
-        tv_nsec: dur.subsec_nanos().into(),
+        tv_nsec: (dur.subsec_nanos() as libc::c_long).into(),
     };
 
     // Timeout needs to be mutable since it is modified on NetBSD 9.0 and
