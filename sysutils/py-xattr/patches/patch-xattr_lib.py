$NetBSD: patch-xattr_lib.py,v 1.1 2014/03/21 14:06:01 wiz Exp $

Set modulename so cffi doesn't have to invent them.

--- xattr/lib.py.orig	2013-07-22 20:10:15.000000000 +0000
+++ xattr/lib.py
@@ -589,7 +589,7 @@ static ssize_t xattr_flistxattr(int fd, 
 #ifndef XATTR_NOSECURITY
 #define XATTR_NOSECURITY 0x0008
 #endif
-""", ext_package='xattr')
+""", ext_package='xattr', modulename='xattr')
 
 XATTR_NOFOLLOW = lib.XATTR_NOFOLLOW
 XATTR_CREATE = lib.XATTR_CREATE
