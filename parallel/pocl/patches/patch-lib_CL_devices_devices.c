$NetBSD: patch-lib_CL_devices_devices.c,v 1.1 2021/06/10 09:57:40 nia Exp $

Add support for non-Linux unixes.

--- lib/CL/devices/devices.c.orig	2021-05-19 08:12:19.000000000 +0000
+++ lib/CL/devices/devices.c
@@ -27,7 +27,7 @@
 #include <string.h>
 #include <ctype.h>
 
-#ifdef __linux__
+#if !defined(_WIN32) && !defined(__APPLE__)
 #include <limits.h>
 #include <signal.h>
 #include <stdio.h>
@@ -70,7 +70,7 @@
 #define PATH_MAX 4096
 #endif
 
-#ifdef HAVE_LIBDL
+#ifdef HAVE_DLFCN_H
 #if defined(__APPLE__)
 #define _DARWIN_C_SOURCE
 #endif
@@ -303,7 +303,7 @@ str_toupper(char *out, const char *in)
  */
 
 #ifdef ENABLE_HOST_CPU_DEVICES
-#ifdef __linux__
+#if !defined(_WIN32) && !defined(__APPLE__)
 #ifdef __x86_64__
 
 #define DIV_OPCODE_SIZE 1
@@ -335,7 +335,11 @@ sigfpe_signal_handler (int signo, siginf
 {
   ucontext_t *uc;
   uc = (ucontext_t *)data;
+#ifdef __NetBSD__
+  unsigned char *eip = (unsigned char *)(uc->uc_mcontext.__gregs[_REG_RIP]);
+#else
   unsigned char *eip = (unsigned char *)(uc->uc_mcontext.gregs[REG_RIP]);
+#endif
 
   if ((signo == SIGFPE)
       && ((si->si_code == FPE_INTDIV) || (si->si_code == FPE_INTOVF)))
@@ -384,7 +388,11 @@ sigfpe_signal_handler (int signo, siginf
             n += IP_RELATIVE_INDEXING;
         }
 
+#ifdef __NetBSD__
+      uc->uc_mcontext.__gregs[_REG_RIP] += n;
+#else
       uc->uc_mcontext.gregs[REG_RIP] += n;
+#endif
       return;
     }
   else
@@ -546,7 +554,7 @@ pocl_init_devices ()
 
 
 #ifdef ENABLE_HOST_CPU_DEVICES
-#ifdef __linux__
+#if !defined(_WIN32) && !defined(__APPLE__)
 #ifdef __x86_64__
 
   if (pocl_get_bool_option ("POCL_SIGFPE_HANDLER", 1))
