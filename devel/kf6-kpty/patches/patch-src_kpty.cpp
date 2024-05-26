$NetBSD: patch-src_kpty.cpp,v 1.1 2024/05/26 12:02:20 markd Exp $

NetBSD loginx() complains if ut_type not set before calling

--- src/kpty.cpp.orig	2022-04-02 10:26:01.000000000 +0000
+++ src/kpty.cpp
@@ -10,6 +10,7 @@
 
 #include "kpty_p.h"
 
+#include <QFile>
 #include <QProcess>
 #include <kpty_debug.h>
 
@@ -168,7 +169,7 @@ KPtyPrivate::~KPtyPrivate()
 bool KPtyPrivate::chownpty(bool grant)
 {
     return !QProcess::execute(QFile::decodeName(CMAKE_INSTALL_PREFIX "/" KDE_INSTALL_LIBEXECDIR_KF "/kgrantpty"),
-                              QStringList() << (grant ? "--grant" : "--revoke") << QString::number(masterFd));
+                              QStringList() << (grant ? QStringLiteral("--grant") : QStringLiteral("--revoke")) << QString::number(masterFd));
 }
 #endif
 
@@ -260,6 +261,7 @@ bool KPty::open()
     }
 #endif // HAVE_PTSNAME || TIOCGPTN
 
+#if 0
     // Linux device names, FIXME: Trouble on other systems?
     for (const char *s3 = "pqrstuvwxyzabcde"; *s3; s3++) {
         for (const char *s4 = "0123456789abcdef"; *s4; s4++) {
@@ -289,8 +291,10 @@ bool KPty::open()
 
     qCWarning(KPTY_LOG) << "Can't open a pseudo teletype";
     return false;
+#endif
 
 gotpty:
+#if 0
     QFileInfo info(d->ttyName.data());
     if (!info.exists()) {
         return false; // this just cannot happen ... *cough*  Yeah right, I just
@@ -302,14 +306,15 @@ gotpty:
         && !d->chownpty(true)) {
         qCWarning(KPTY_LOG) << "chownpty failed for device " << ptyName << "::" << d->ttyName << "\nThis means the communication can be eavesdropped." << endl;
     }
+#endif
 
 grantedpt:
 
-#ifdef HAVE_REVOKE
+#if HAVE_REVOKE
     revoke(d->ttyName.data());
 #endif
 
-#ifdef HAVE_UNLOCKPT
+#if HAVE_UNLOCKPT
     unlockpt(d->masterFd);
 #elif defined(TIOCSPTLCK)
     int flag = 0;
@@ -502,11 +507,14 @@ void KPty::login(const char *user, const
 #endif
 
 #if HAVE_UTMPX
-    gettimeofday(&l_struct.ut_tv, 0);
+    gettimeofday(&l_struct.ut_tv, nullptr);
 #else
     l_struct.ut_time = time(0);
 #endif
 
+#if HAVE_STRUCT_UTMP_UT_TYPE
+    l_struct.ut_type = USER_PROCESS;
+#endif
 #if HAVE_LOGIN
 #if HAVE_LOGINX
     ::loginx(&l_struct);
@@ -514,9 +522,6 @@ void KPty::login(const char *user, const
     ::login(&l_struct);
 #endif
 #else
-#if HAVE_STRUCT_UTMP_UT_TYPE
-    l_struct.ut_type = USER_PROCESS;
-#endif
 #if HAVE_STRUCT_UTMP_UT_PID
     l_struct.ut_pid = getpid();
 #if HAVE_STRUCT_UTMP_UT_SESSION
@@ -605,7 +610,7 @@ void KPty::logout()
         ut->ut_type = DEAD_PROCESS;
 #endif
 #if HAVE_UTMPX
-        gettimeofday(&(ut->ut_tv), 0);
+        gettimeofday(&(ut->ut_tv), nullptr);
         pututxline(ut);
     }
     endutxent();
