$NetBSD: patch-src_common_semaphores__c.c,v 1.1 2025/07/10 12:43:03 dkazankov Exp $

Fix runtime error caused semaphore names on NetBSD

--- src/common/semaphores_c.c.orig	2023-01-05 11:22:11.000000000 +0200
+++ src/common/semaphores_c.c
@@ -30,8 +30,33 @@
 #include <stdio.h>
 #include <stdlib.h>
 
+#if defined (__NetBSD__)
+char* __netbsd_sem_name(const char *name) {
+  size_t len = strlen (name);
+  char *sem_name = calloc (len+2, sizeof(char));
+  if (sem_name == NULL) {
+    return (char *) name;
+  }
+  char *p = sem_name;
+  if (len > 0 && name[0] != '/') {
+    sem_name[0] = '/';
+    p++;
+  }
+  strcpy (p, name);
+  return sem_name;
+}
+#endif
+
 sem_t* create_semaphore (const char *name, unsigned int init) {
+#if defined (__NetBSD__)
+  char *sem_name = __netbsd_sem_name (name);
+  sem_t* r = sem_open (sem_name, O_CREAT | O_EXCL, 0600, init);
+  if (sem_name != name) {
+    free (sem_name);
+  }
+#else
   sem_t* r = sem_open (name, O_CREAT | O_EXCL, 0600, init);
+#endif
   if (r == SEM_FAILED) {
     perror("failed to create semaphore");
     exit(1);
@@ -40,7 +65,15 @@
 }
 
 sem_t* open_semaphore (const char *name) {
+#if defined (__NetBSD__)
+  char *sem_name = __netbsd_sem_name (name);
+  sem_t* r = sem_open (sem_name, 0);
+  if (sem_name != name) {
+    free (sem_name);
+  }
+#else
   sem_t* r = sem_open (name, 0);
+#endif
   if (r == SEM_FAILED) {
     perror("failed to open semaphore");
     exit(1);
@@ -70,7 +103,16 @@
 }
 
 void delete_semaphore (const char *name) {
+#if defined (__NetBSD__)
+  char *sem_name = __netbsd_sem_name (name);
+  int r = sem_unlink (sem_name);
+  if (sem_name != name) {
+    free (sem_name);
+  }
+  if (r == -1) {
+#else
   if (sem_unlink(name) == -1) {
+#endif
     //  ignore errors of deleting on purpose
   }
 }
