$NetBSD: patch-src_main.cc,v 1.2 2022/07/11 11:49:48 adam Exp $

Fix build on NetBSD

--- src/main.cc.orig	2022-05-03 17:39:25.000000000 +0000
+++ src/main.cc
@@ -287,7 +287,7 @@ int main(int argc, char** argv, char** e
 // macOS does this differently, setgid and setuid are basically doing the same
 // as setresuid and setresgid on linux: setting all of real{u,g}id, effective{u,g}id and saved-set{u,g}id
 // Solaroid systems are likewise missing setresgid and setresuid
-#if defined(__APPLE__) || defined(SOLARIS) || defined(__CYGWIN__) || defined(__HAIKU__)
+#if defined(__APPLE__) || defined(SOLARIS) || defined(__CYGWIN__) || defined(__HAIKU__) || defined(__NetBSD__)
             // set group-ids, then add. groups, last user-ids, all need to succeed
             if (0 != setgid(userId->pw_gid) || 0 != initgroups(userId->pw_name, userId->pw_gid) || 0 != setuid(userId->pw_uid)) {
 #else
