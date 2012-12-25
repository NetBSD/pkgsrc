$NetBSD: patch-lib_panic_panic.c,v 1.1 2012/12/25 21:02:15 joerg Exp $

--- lib/panic/panic.c.orig	2012-12-25 19:42:53.000000000 +0000
+++ lib/panic/panic.c
@@ -497,7 +497,7 @@ Panic_Panic(const char *format,
    case 0:
       break;
    case 1:
-      Log(buf);
+      Log("%s", buf);
       Log("Panic loop\n");
    default:
       fprintf(stderr, "Panic loop\n");
@@ -510,7 +510,7 @@ Panic_Panic(const char *format,
     * the log file on exit.
     */
 
-   Log(buf);
+   Log("%s", buf);
    Util_Backtrace(0);
    Log_SetAlwaysKeep(TRUE);
 
