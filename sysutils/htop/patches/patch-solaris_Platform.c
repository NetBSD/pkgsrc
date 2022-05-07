$NetBSD: patch-solaris_Platform.c,v 1.1 2022/05/07 07:35:06 nia Exp $

Ensure buffer for environment is large enough

https://github.com/htop-dev/htop/pull/997

--- solaris/Platform.c.orig	2021-11-30 01:03:21.000000000 +0000
+++ solaris/Platform.c
@@ -259,16 +259,21 @@ static int Platform_buildenv(void* accum
    envAccum* accump = accum;
    (void) Phandle;
    (void) addr;
+
    size_t thissz = strlen(str);
-   if ((thissz + 2) > (accump->capacity - accump->size)) {
-      accump->env = xRealloc(accump->env, accump->capacity *= 2);
-   }
-   if ((thissz + 2) > (accump->capacity - accump->size)) {
-      return 1;
+
+   while ((thissz + 2) > (accump->capacity - accump->size)) {
+      if (accump->capacity > (SIZE_MAX / 2))
+         return 1;
+
+      accump->capacity *= 2;
+      accump->env = xRealloc(accump->env, accump->capacity);
    }
-   strlcpy( accump->env + accump->size, str, (accump->capacity - accump->size));
+
+   strlcpy( accump->env + accump->size, str, accump->capacity - accump->size);
    strncpy( accump->env + accump->size + thissz + 1, "\n", 2);
-   accump->size = accump->size + thissz + 1;
+
+   accump->size += thissz + 1;
    return 0;
 }
 
@@ -291,7 +296,8 @@ char* Platform_getProcessEnv(pid_t pid) 
    Prelease(Phandle, 0);
 
    strncpy( envBuilder.env + envBuilder.size, "\0", 1);
-   return envBuilder.env;
+
+   return xRealloc(envBuilder.env, envBuilder.size + 1);
 }
 
 char* Platform_getInodeFilename(pid_t pid, ino_t inode) {
