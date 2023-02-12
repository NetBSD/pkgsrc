$NetBSD: patch-src_OSD_OSD__signal.cxx,v 1.1 2023/02/12 14:42:25 tnn Exp $

From cad/oce:
Define SIGFPE macros on SunOS.
Avoid overlapping reference in case statements.
Respect the reality as CMake found it, there might not be libsunmath.
1.1 2017/01/20 11:00:50 fhajny

--- src/OSD/OSD_signal.cxx.orig	2022-11-11 22:19:44.000000000 +0000
+++ src/OSD/OSD_signal.cxx
@@ -20,6 +20,18 @@
 
 #include <Standard_WarningDisableFunctionCast.hxx>
 
+#if defined(__sun)
+# include <alloca.h>
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
 static OSD_SignalMode OSD_WasSetSignal = OSD_SignalMode_AsIs;
 static Standard_Integer OSD_SignalStackTraceLength = 0;
 
@@ -846,6 +858,7 @@ static void Handler (const int theSignal
     break;
 #endif
   case SIGFPE:
+  {
     sigaddset(&set, SIGFPE);
     sigprocmask(SIG_UNBLOCK, &set, NULL) ;
 #ifdef __linux__
@@ -856,6 +869,7 @@ static void Handler (const int theSignal
     break;
 #else
     // Reste SOLARIS
+    siginfo_t * aSigInfo = NULL;
     if (aSigInfo) {
       switch(aSigInfo->si_code) {
       case FPE_FLTDIV_TRAP :
@@ -888,6 +902,7 @@ static void Handler (const int theSignal
     }
 #endif
     break;
+  }
   default:
 #ifdef OCCT_DEBUG
     std::cout << "Unexpected signal " << theSignal << std::endl ;
@@ -984,7 +999,7 @@ void OSD::SetFloatingSignal (Standard_Bo
   {
     fedisableexcept (_OSD_FPX);
   }
-#elif defined (__sun) || defined (SOLARIS)
+#elif (defined (__sun) || defined (SOLARIS)) && HAVE_SUNMATH
   int aSunStat = 0;
   sigfpe_handler_type anFpeHandler = (theFloatingSignal ? (sigfpe_handler_type)Handler : NULL);
   aSunStat = ieee_handler ("set", "invalid",  anFpeHandler);
