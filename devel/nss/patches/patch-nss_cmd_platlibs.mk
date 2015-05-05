$NetBSD: patch-nss_cmd_platlibs.mk,v 1.1 2015/05/05 21:42:19 ryoon Exp $

--- nss/cmd/platlibs.mk.orig	2015-04-30 20:00:23.000000000 +0000
+++ nss/cmd/platlibs.mk
@@ -135,8 +135,8 @@ endif
 # $(PROGRAM) has NO explicit dependencies on $(EXTRA_SHARED_LIBS)
 # $(EXTRA_SHARED_LIBS) come before $(OS_LIBS), except on AIX.
 EXTRA_SHARED_LIBS += \
-	-L$(SQLITE_LIB_DIR) \
-	-l$(SQLITE_LIB_NAME) \
+	`pkg-config --libs-only-L sqlite3` \
+	`pkg-config --libs-only-l sqlite3` \
 	-L$(NSSUTIL_LIB_DIR) \
 	-lnssutil3 \
 	-L$(NSPR_LIB_DIR) \
