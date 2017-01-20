$NetBSD: patch-src_OSD_OSD__signal.cxx,v 1.1 2017/01/20 11:00:50 fhajny Exp $

Define SIGFPE macros on SunOS.
Avoid overlapping reference in case statements.
Respect the reality as CMake found it, there might not be libsunmath.

--- src/OSD/OSD_signal.cxx.orig	2017-01-13 05:34:36.000000000 +0000
+++ src/OSD/OSD_signal.cxx
@@ -55,6 +55,17 @@ ACT_SIGIO_HANDLER *ADR_ACT_SIGIO_HANDLER
 typedef void (* SIG_PFV) (int);
 #endif
 
+#if defined(__sun)
+# include <sys/siginfo.h>
+# define FPE_FLTDIV_TRAP FPE_FLTDIV
+# define FPE_INTDIV_TRAP FPE_INTDIV
+# define FPE_FLTOVF_TRAP FPE_FLTOVF
+# define FPE_INTOVF_TRAP FPE_INTOVF
+# define FPE_FLTUND_TRAP FPE_FLTUND
+# define FPE_FLTRES_TRAP FPE_FLTRES
+# define FPE_FLTINV_TRAP FPE_FLTINV
+#endif
+
 #ifdef __GNUC__
 # include <stdlib.h>
 # include <stdio.h>
@@ -265,6 +276,7 @@ static void Handler (const int theSignal
     break;
 #endif
   case SIGFPE:
+  {
     sigaddset(&set, SIGFPE);
     sigprocmask(SIG_UNBLOCK, &set, NULL) ;
 #ifdef DECOSF1
@@ -277,6 +289,7 @@ static void Handler (const int theSignal
     break;
 #else
     // Reste SOLARIS
+    siginfo_t * aSigInfo = NULL;
     if (aSigInfo) {
       switch(aSigInfo->si_code) {
       case FPE_FLTDIV_TRAP :
@@ -309,6 +322,7 @@ static void Handler (const int theSignal
     }
 #endif
     break;
+  }
 #if defined (__sgi) || defined(IRIX)
   case SIGTRAP:
     sigaddset(&set, SIGTRAP);
@@ -380,7 +394,7 @@ void OSD::SetSignal(const Standard_Boole
 
   if( aFloatingSignal ) {
     //==== Enable the floating point exceptions ===============
-#if defined (__sun) || defined (SOLARIS)
+#if ( defined (__sun) || defined (SOLARIS) ) && HAVE_SUNMATH
     sigfpe_handler_type PHandler = (sigfpe_handler_type) Handler ;
     stat = ieee_handler("set", "invalid",  PHandler);
     stat = ieee_handler("set", "division", PHandler) || stat;
