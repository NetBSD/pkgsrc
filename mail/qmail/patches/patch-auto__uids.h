$NetBSD: patch-auto__uids.h,v 1.1.2.1 2017/04/17 16:08:22 bsiegert Exp $

Look up user/group IDs at runtime. Based on Paul Fox's getpwnam.patch.

--- auto_uids.h.orig	1998-06-15 10:53:16.000000000 +0000
+++ auto_uids.h
@@ -1,16 +1,29 @@
 #ifndef AUTO_UIDS_H
 #define AUTO_UIDS_H
 
-extern int auto_uida;
-extern int auto_uidd;
-extern int auto_uidl;
-extern int auto_uido;
-extern int auto_uidp;
-extern int auto_uidq;
-extern int auto_uidr;
-extern int auto_uids;
+#define ID_OWNER   0
+#define ID_ALIAS   1
+#define ID_DAEMON  2
+#define ID_LOG     3
+#define ID_PASSWD  4
+#define ID_QUEUE   5
+#define ID_REMOTE  6
+#define ID_SEND    7
+#define ID_QMAIL   8
+#define ID_NOFILES 9
 
-extern int auto_gidn;
-extern int auto_gidq;
+#define auto_uido qm_id(ID_OWNER)
+#define auto_uida qm_id(ID_ALIAS)
+#define auto_uidd qm_id(ID_DAEMON)
+#define auto_uidl qm_id(ID_LOG)
+#define auto_uidp qm_id(ID_PASSWD)
+#define auto_uidq qm_id(ID_QUEUE)
+#define auto_uidr qm_id(ID_REMOTE)
+#define auto_uids qm_id(ID_SEND)
+
+#define auto_gidq qm_id(ID_QMAIL)
+#define auto_gidn qm_id(ID_NOFILES)
+
+extern int qm_id();
 
 #endif
