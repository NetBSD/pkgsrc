$NetBSD: patch-pkgsrc__user__destdir__fake__uids.h,v 1.1 2017/03/20 16:23:20 schmonz Exp $

Install files without needing real qmail users to exist yet.

--- pkgsrc_user_destdir_fake_uids.h.orig	2017-03-20 13:49:34.000000000 +0000
+++ pkgsrc_user_destdir_fake_uids.h
@@ -0,0 +1,16 @@
+#ifndef AUTO_UIDS_H
+#define AUTO_UIDS_H
+
+#define auto_uido  0
+#define auto_uida  1
+#define auto_uidd  2
+#define auto_uidl  3
+#define auto_uidp  4
+#define auto_uidq  5
+#define auto_uidr  6
+#define auto_uids  7
+
+#define auto_gidq  8
+#define auto_gidn  9
+
+#endif
