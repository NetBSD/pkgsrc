$NetBSD: patch-lib_exceptionhandler_exceptionhandler.cpp,v 1.3 2020/01/27 19:35:54 triaxx Exp $

Disable unsupported sigcodes for DragonFlyBSD.

--- lib/exceptionhandler/exceptionhandler.cpp.orig	2019-08-31 18:17:21.000000000 +0000
+++ lib/exceptionhandler/exceptionhandler.cpp
@@ -23,6 +23,7 @@
 #include "lib/framework/string_ext.h"
 #include "exceptionhandler.h"
 #include "dumpinfo.h"
+#include <errno.h>
 
 #if defined(WZ_OS_WIN)
 #include <tchar.h>
@@ -122,18 +123,21 @@ static const char *wz_strsignal(int sign
 	case SIGBUS:
 		switch (sigcode)
 		{
+#if !defined(__DragonFly__)
 		case BUS_ADRALN:
 			return "SIGBUS: Access to an undefined portion of a memory object: Invalid address alignment";
 		case BUS_ADRERR:
 			return "SIGBUS: Access to an undefined portion of a memory object: Nonexistent physical address";
 		case BUS_OBJERR:
 			return "SIGBUS: Access to an undefined portion of a memory object: Object-specific hardware error";
+#endif
 		default:
 			return "SIGBUS: Access to an undefined portion of a memory object";
 		}
 	case SIGFPE:
 		switch (sigcode)
 		{
+#if !defined(__DragonFly__)
 		case FPE_INTDIV:
 			return "SIGFPE: Erroneous arithmetic operation: Integer divide by zero";
 		case FPE_INTOVF:
@@ -150,6 +154,7 @@ static const char *wz_strsignal(int sign
 			return "SIGFPE: Erroneous arithmetic operation: Invalid floating-point operation";
 		case FPE_FLTSUB:
 			return "SIGFPE: Erroneous arithmetic operation: Subscript out of range";
+#endif
 		default:
 			return "SIGFPE: Erroneous arithmetic operation";
 		};
@@ -158,6 +163,7 @@ static const char *wz_strsignal(int sign
 	case SIGILL:
 		switch (sigcode)
 		{
+#if !defined(__DragonFly__)
 		case ILL_ILLOPC:
 			return "SIGILL: Illegal instruction: Illegal opcode";
 		case ILL_ILLOPN:
@@ -174,6 +180,7 @@ static const char *wz_strsignal(int sign
 			return "SIGILL: Illegal instruction: Coprocessor error";
 		case ILL_BADSTK:
 			return "SIGILL: Illegal instruction: Internal stack error";
+#endif
 		default:
 			return "SIGILL: Illegal instruction";
 		}
@@ -188,10 +195,12 @@ static const char *wz_strsignal(int sign
 	case SIGSEGV:
 		switch (sigcode)
 		{
+#if !defined(__DragonFly__)
 		case SEGV_MAPERR:
 			return "SIGSEGV: Invalid memory reference: Address not mapped to object";
 		case SEGV_ACCERR:
 			return "SIGSEGV: Invalid memory reference: Invalid permissions for mapped object";
+#endif
 		default:
 			return "SIGSEGV: Invalid memory reference";
 		}
@@ -209,10 +218,12 @@ static const char *wz_strsignal(int sign
 	case SIGTRAP:
 		switch (sigcode)
 		{
+#if !defined(__DragonFly__)
 		case TRAP_BRKPT:
 			return "SIGTRAP: Trace/breakpoint trap: Process breakpoint";
 		case TRAP_TRACE:
 			return "SIGTRAP: Trace/breakpoint trap: Process trace trap";
+#endif
 		default:
 			return "SIGTRAP: Trace/breakpoint trap";
 		}
