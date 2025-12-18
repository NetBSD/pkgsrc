$NetBSD: patch-debugger_mcs51_sdcdb.c,v 1.1 2025/12/18 15:43:42 ryoon Exp $

--- debugger/mcs51/sdcdb.c.orig	2007-08-23 20:03:39.000000000 +0000
+++ debugger/mcs51/sdcdb.c
@@ -21,6 +21,8 @@
    what you give them.   Help stamp out software-hoarding!
 -------------------------------------------------------------------------*/
 
+#include <unistd.h>
+
 #include "sdcdb.h"
 #include "symtab.h"
 #include "simi.h"
@@ -1603,7 +1605,7 @@ static void parseCmdLine (int argc, char
             }
 
             if (strncmp(argv[i],"-cd=",4) == 0) {
-                chdir(argv[i][4]);
+                chdir(&argv[i][4]);
                 continue;
             }
 
@@ -1724,6 +1726,7 @@ sigintr(int sig)
 
 #ifndef _WIN32
 /* the only child can be the simulator */
+#include <sys/wait.h>
 static void sigchld(int sig)
 {
     /* the only child can be the simulator */
