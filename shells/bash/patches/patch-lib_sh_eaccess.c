$NetBSD: patch-lib_sh_eaccess.c,v 1.1 2012/07/18 15:43:12 spz Exp $

from ftp://ftp.gnu.org/pub/gnu/bash/bash-4.2-patches/bash42-033

   Bash-Release:	4.2
   Patch-ID:	bash42-033
   
   Bug-Reported-by:	David Leverton <levertond@googlemail.com>
   Bug-Reference-ID:	<4FCCE737.1060603@googlemail.com>
   Bug-Reference-URL:
   
   Bug-Description:
   
   Bash uses a static buffer when expanding the /dev/fd prefix for the test
   and conditional commands, among other uses, when it should use a dynamic
   buffer to avoid buffer overflow.

--- lib/sh/eaccess.c.orig	2011-01-09 01:50:10.000000000 +0000
+++ lib/sh/eaccess.c
@@ -82,6 +82,8 @@ sh_stat (path, finfo)
      const char *path;
      struct stat *finfo;
 {
+  static char *pbuf = 0;
+
   if (*path == '\0')
     {
       errno = ENOENT;
@@ -106,7 +108,7 @@ sh_stat (path, finfo)
      trailing slash.  Make sure /dev/fd/xx really uses DEV_FD_PREFIX/xx.
      On most systems, with the notable exception of linux, this is
      effectively a no-op. */
-      char pbuf[32];
+      pbuf = xrealloc (pbuf, sizeof (DEV_FD_PREFIX) + strlen (path + 8));
       strcpy (pbuf, DEV_FD_PREFIX);
       strcat (pbuf, path + 8);
       return (stat (pbuf, finfo));
