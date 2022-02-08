$NetBSD: patch-src_main.cc,v 1.1 2022/02/08 06:26:49 khorben Exp $

Fix build on NetBSD

--- src/main.cc.orig	2021-09-30 19:23:27.000000000 +0000
+++ src/main.cc
@@ -266,7 +266,7 @@ int main(int argc, char** argv, char** e
 // mac os x does this differently, setgid and setuid are basically doing the same
 // as setresuid and setresgid on linux: setting all of real{u,g}id, effective{u,g}id and saved-set{u,g}id
 // Solaroid systems are likewise missing setresgid and setresuid
-#if defined(__APPLE__) || defined(SOLARIS) || defined(__CYGWIN__) || defined(__HAIKU__)
+#if defined(__APPLE__) || defined(SOLARIS) || defined(__CYGWIN__) || defined(__HAIKU__) || defined(__NetBSD__)
             // set group-ids, then add. groups, last user-ids, all need to succeed
             if (0 != setgid(user_id->pw_gid) || 0 != initgroups(user_id->pw_name, user_id->pw_gid) || 0 != setuid(user_id->pw_uid)) {
 #else
