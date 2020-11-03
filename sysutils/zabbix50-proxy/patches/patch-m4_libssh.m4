$NetBSD: patch-m4_libssh.m4,v 1.1 2020/11/03 22:45:39 otis Exp $

Fix libssh >= 0.9.5 detection.

--- m4/libssh.m4.orig	2020-05-10 17:36:06.000000000 +0000
+++ m4/libssh.m4
@@ -83,13 +83,19 @@ AC_HELP_STRING([--with-ssh@<:@=DIR@:>@],
          SSH_LDFLAGS=-L/usr/lib
          SSH_LIBS="-lssh"
          found_ssh="yes"
-	 LIBSSH_ACCEPT_VERSION([/usr/include/libssh/libssh.h])
+	 LIBSSH_ACCEPT_VERSION([/usr/include/libssh/libssh_version.h])
+	 if test "x$accept_ssh_version" = "xno"; then
+	    LIBSSH_ACCEPT_VERSION([/usr/include/libssh/libssh.h])
+	 fi
        elif test -f /usr/local/include/libssh/libssh.h; then
          SSH_CFLAGS=-I/usr/local/include
          SSH_LDFLAGS=-L/usr/local/lib
          SSH_LIBS="-lssh"
          found_ssh="yes"
-	 LIBSSH_ACCEPT_VERSION([/usr/local/include/libssh/libssh.h])
+	 LIBSSH_ACCEPT_VERSION([/usr/local/include/libssh/libssh_version.h])
+	 if test "x$accept_ssh_version" = "xno"; then
+	    LIBSSH_ACCEPT_VERSION([/usr/local/include/libssh/libssh.h])
+	 fi
        else #libraries are not found in default directories
          found_ssh="no"
          AC_MSG_RESULT(no)
@@ -100,7 +106,10 @@ AC_HELP_STRING([--with-ssh@<:@=DIR@:>@],
          SSH_LDFLAGS=-L$_libssh_dir/lib
          SSH_LIBS="-lssh"
          found_ssh="yes"
-	 LIBSSH_ACCEPT_VERSION([$_libssh_dir/include/libssh/libssh.h])
+	 LIBSSH_ACCEPT_VERSION([$_libssh_dir/include/libssh/libssh_version.h])
+	 if test "x$accept_ssh_version" = "xno"; then
+	    LIBSSH_ACCEPT_VERSION([$_libssh_dir/include/libssh/libssh.h])
+	 fi
        else #if test -f $_libssh_dir/include/libssh/libssh.h; then
          found_ssh="no"
          AC_MSG_RESULT(no)
