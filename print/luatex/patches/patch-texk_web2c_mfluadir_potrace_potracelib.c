$NetBSD: patch-texk_web2c_mfluadir_potrace_potracelib.c,v 1.1 2022/04/17 10:41:27 markd Exp $

Hack to pick up the correct config.h 

--- texk/web2c/mfluadir/potrace/potracelib.c.orig	2022-02-12 18:02:57.000000000 +0000
+++ texk/web2c/mfluadir/potrace/potracelib.c
@@ -3,7 +3,7 @@
    by the GNU General Public License. See the file COPYING for details. */
 
 #ifdef HAVE_CONFIG_H
-#include <config.h>
+#include <../potrace/config.h>
 #endif
 
 #include <stdlib.h>
