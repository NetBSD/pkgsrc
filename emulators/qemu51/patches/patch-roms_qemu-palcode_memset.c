$NetBSD: patch-roms_qemu-palcode_memset.c,v 1.1 2021/02/20 22:55:19 ryoon Exp $

Include local header file for prototypes.

--- roms/qemu-palcode/memset.c.orig	2020-10-04 16:26:11.159949099 +0000
+++ roms/qemu-palcode/memset.c	2020-10-04 16:29:02.795766148 +0000
@@ -19,7 +19,7 @@
    <http://www.gnu.org/licenses/>.  */
 
 
-#include <string.h>
+#include "protos.h"
 
 void *memset(void *optr, int ival, unsigned long size)
 {
