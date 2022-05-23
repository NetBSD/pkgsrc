$NetBSD: patch-src_ut_ut__os__aix.c,v 1.1 2022/05/23 19:10:03 plunky Exp $

1. suppress printing of OS name 'Linux', since it may not be
2. disable glibc version check
3. also look for gvim
4. do not use obsolete non-standard definitions

--- src/ut/ut_os_aix.c.orig	2021-07-18 06:38:57.000000000 +0000
+++ src/ut/ut_os_aix.c
@@ -335,7 +335,6 @@ extern int errno;
   char    s1[256];
 
 
-  printf("%s\n",OS_get_os_bits());  // 32/64-bit
 
 
   // Linux-Version: /proc/version or "uname -a"
@@ -406,6 +405,7 @@ extern int errno;
 
   // static float versionLinked = 2.8;
 
+#if 0
   char   cBuf[256], *p1;
   size_t i1;
   int    iv1, iv2;
@@ -435,6 +435,7 @@ extern int errno;
       return -1;
     }
   }
+#endif
 
   return 0;
 
@@ -1017,6 +1018,8 @@ extern int errno;
     strcpy(txbuf, "kate ");
   if(system("which dtpad 1>/dev/null 2>/dev/null") == 0)
     strcpy(txbuf, "dtpad ");
+  if(system("which gvim 1>/dev/null 2>/dev/null") == 0)
+    strcpy(txbuf, "gvim ");
 
   if(strlen(txbuf) < 2) { 
     printf(" **** no Editor found\n");
@@ -1634,10 +1637,10 @@ extern int errno;
   void *catch;
   int ret;
 
-  catch = signal(SIGCLD, SIG_DFL);
+  catch = signal(SIGCHLD, SIG_DFL);
   ret = system(buf);
 
-  signal(SIGCLD, catch);
+  signal(SIGCHLD, catch);
   if (ret) { perror(buf); }
 
   return(ret);
