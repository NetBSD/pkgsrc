$NetBSD: patch-src_ssDCmd.c,v 1.1 2016/08/14 18:27:05 scole Exp $

Use correct line separators.

--- src/ssDCmd.c.orig	2008-02-04 23:11:38.000000000 -0500
+++ src/ssDCmd.c	2016-04-17 06:26:02.000000000 -0400
@@ -42,6 +42,7 @@
 #include "libcore.h"
 #include "dos.h"
 #include "libtrace.h"
+#include "line_separator.h"
 
 #define MAXFILEDEPTH	16
 #define MAXCMDLEN	4000
@@ -630,7 +631,7 @@
 	    p = strtok(NULL, " \t");
 	    ofs = p ? (ADDR)strtoul(p, 0, 16) : 0;
 	    adr = (seg << 4) + ofs + start + symOffset;
-        if ((p = strtok(NULL, " \t\r\n")))
+	    if ((p = strtok(NULL, " \t"LINE_SEPARATOR)))
 		symInsert(p, adr, 0);
 	}
 	(void)fclose(fp);
@@ -733,7 +734,7 @@
 	    p = strtok(NULL, " \t");
 	    ofs = p ? (ADDR)strtoul(p, 0, 16) : 0;
 	    adr = (seg << 4) + ofs + start;
-	    if ((p = strtok(NULL, " \t\r\n")))
+	    if ((p = strtok(NULL, " \t"LINE_SEPARATOR)))
 		symInsert(p, adr, 0);
 	}
 	(void)fclose(fp);
