$NetBSD: patch-include_dcc.h,v 1.1 2024/03/16 13:11:55 nia Exp $

Fixes a security issue with DCC.
https://sourceforge.net/p/bitchx/git/ci/726884b0b076d0a77f7f5c7866caa09a164e8ae9/

--- include/dcc.h.orig	2008-04-30 13:57:56.000000000 +0000
+++ include/dcc.h
@@ -97,6 +97,7 @@
 #define DCC_OFFER	0x00040000
 #define DCC_DELETE	0x00080000
 #define DCC_TWOCLIENTS	0x00100000
+#define DCC_RESUME_REQ 0x00200000
 
 #ifdef NON_BLOCKING_CONNECTS
 #define DCC_CNCT_PEND	0x00200000
