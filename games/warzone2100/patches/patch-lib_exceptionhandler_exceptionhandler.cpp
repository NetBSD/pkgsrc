$NetBSD: patch-lib_exceptionhandler_exceptionhandler.cpp,v 1.1 2018/12/14 17:27:01 triaxx Exp $

Disable unsupported sigcodes for DragonFlyBSD.

--- lib/exceptionhandler/exceptionhandler.cpp.orig	2017-04-23 13:12:16.000000000 +0000
+++ lib/exceptionhandler/exceptionhandler.cpp
@@ -192,18 +192,21 @@ static const char *wz_strsignal(int sign
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
@@ -220,6 +223,7 @@ static const char *wz_strsignal(int sign
 			return "SIGFPE: Erroneous arithmetic operation: Invalid floating-point operation";
 		case FPE_FLTSUB:
 			return "SIGFPE: Erroneous arithmetic operation: Subscript out of range";
+#endif
 		default:
 			return "SIGFPE: Erroneous arithmetic operation";
 		};
@@ -228,6 +232,7 @@ static const char *wz_strsignal(int sign
 	case SIGILL:
 		switch (sigcode)
 		{
+#if !defined(__DragonFly__)
 		case ILL_ILLOPC:
 			return "SIGILL: Illegal instruction: Illegal opcode";
 		case ILL_ILLOPN:
@@ -244,6 +249,7 @@ static const char *wz_strsignal(int sign
 			return "SIGILL: Illegal instruction: Coprocessor error";
 		case ILL_BADSTK:
 			return "SIGILL: Illegal instruction: Internal stack error";
+#endif
 		default:
 			return "SIGILL: Illegal instruction";
 		}
@@ -258,10 +264,12 @@ static const char *wz_strsignal(int sign
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
@@ -279,10 +287,12 @@ static const char *wz_strsignal(int sign
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
