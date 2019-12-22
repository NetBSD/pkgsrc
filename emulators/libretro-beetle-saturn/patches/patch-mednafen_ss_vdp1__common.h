$NetBSD: patch-mednafen_ss_vdp1__common.h,v 1.1 2019/12/22 22:24:22 joerg Exp $

Needed for abs.

--- mednafen/ss/vdp1_common.h.orig	2019-12-22 18:25:53.444872809 +0000
+++ mednafen/ss/vdp1_common.h
@@ -20,6 +20,7 @@
 */
 
 #include "ss_endian.h"
+#include <stdlib.h>
 
 #ifndef __MDFN_SS_VDP1_COMMON_H
 #define __MDFN_SS_VDP1_COMMON_H
