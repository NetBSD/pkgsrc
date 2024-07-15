$NetBSD: patch-src_config_grb__runtime.cc,v 1.1 2024/07/15 10:28:43 adam Exp $

Fix build on NetBSD.

--- src/config/grb_runtime.cc.orig	2024-07-15 09:47:21.629452221 +0000
+++ src/config/grb_runtime.cc
@@ -258,7 +258,7 @@ bool GerberaRuntime::setUser(const std::
     // macOS does this differently, setgid and setuid are basically doing the same
     // as setresuid and setresgid on linux: setting all of real{u,g}id, effective{u,g}id and saved-set{u,g}id
     // Solaroid systems are likewise missing setresgid and setresuid
-#if defined(__APPLE__) || defined(SOLARIS) || defined(__CYGWIN__) || defined(__HAIKU__)
+#if defined(__APPLE__) || defined(SOLARIS) || defined(__CYGWIN__) || defined(__HAIKU__) || defined(__NetBSD__)
     // set group-ids, then add. groups, last user-ids, all need to succeed
     if (0 != setgid(userId->pw_gid) || 0 != initgroups(userId->pw_name, userId->pw_gid) || 0 != setuid(userId->pw_uid)) //
 #else
