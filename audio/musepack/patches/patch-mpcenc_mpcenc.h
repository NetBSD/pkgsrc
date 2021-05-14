$NetBSD: patch-mpcenc_mpcenc.h,v 1.1 2021/05/14 03:14:19 mcf Exp $

Fix build on linux-musl.

Upstream: http://trac.musepack.net/musepack/changeset/492/

--- mpcenc/mpcenc.h.orig	Fri May 14 03:06:14 2021
+++ mpcenc/mpcenc.h
@@ -50,7 +50,7 @@
 # include <unistd.h>
 #endif
 
-#if   defined __linux__
+#if   defined __GLIBC__
 #  include <fpu_control.h>
 #elif defined __FreeBSD__
 # include <machine/floatingpoint.h>
