$NetBSD: patch-bigstring__unix_src_bigstring__unix.ml,v 1.1 2022/08/19 12:42:34 tnn Exp $

define used in ifdef must be explicitly undefined or defined.
So make sure to undef it first, that way it should have a well defined state.

--- bigstring_unix/src/bigstring_unix.ml.orig	2022-02-15 14:18:18.000000000 +0000
+++ bigstring_unix/src/bigstring_unix.ml
@@ -128,6 +128,8 @@ let pwrite_assume_fd_is_nonblocking fd ~
   check_args ~loc ~pos ~len bstr;
   unsafe_pwrite_assume_fd_is_nonblocking fd ~offset ~pos ~len bstr
 
+[%%undef JSC_NOSIGPIPE]
+
 [%%ifdef JSC_MSG_NOSIGNAL]
 [%%define JSC_NOSIGPIPE]
 [%%endif]
