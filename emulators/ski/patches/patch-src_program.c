$NetBSD: patch-src_program.c,v 1.1 2016/08/14 18:27:05 scole Exp $

Use correct line separators.

--- src/program.c.orig	2008-02-04 23:11:38.000000000 -0500
+++ src/program.c	2016-04-17 06:24:07.000000000 -0400
@@ -43,6 +43,7 @@
 #include "ia_exec.h"
 #include "state.h"
 #include "simmem.h"
+#include "line_separator.h"
 
 static char instPtr(ADDR addr, char *dline);
 static IAinstInfoPtr addrToIAinfo(ADDR adr, BYTE iAmode, unsigned *nbytes);
@@ -268,11 +269,11 @@
 	dasInit(DasPseudoOps|DasTemplate|DasRegNames, prgColumns - 20);
 	dasBundle(&bndl, i0Str, i1Str, i2Str);
 	ipp = instPtr(ofs, i0Str);
-	p += sprintf(p, "%s%c%c %s %s\r\n", srcp, bpn, ipp, buf, i0Str);
+	p += sprintf(p, "%s%c%c %s %s%s", srcp, bpn, ipp, buf, i0Str, LINE_SEPARATOR);
 	if (i1Str[0]) {		/* not MLX */
 	    bpn = ((i = isbpt(ofs + 4)) >= 0) ? (i + '0') : ' ';
 	    ipp = instPtr(ofs + 4, i1Str);
-	    p += sprintf(p, "%c%c %16s %s\r\n", bpn, ipp, "", i1Str);
+	    p += sprintf(p, "%c%c %16s %s%s", bpn, ipp, "", i1Str, LINE_SEPARATOR);
 	    bpn = ((i = isbpt(ofs + 8)) >= 0) ? (i + '0') : ' ';
 	    ipp = instPtr(ofs + 8, i2Str);
 	} else {		/* MLX */
@@ -280,12 +281,12 @@
 		    ? (i + '0') : ' ';
 	    ipp = instPtr(ofs + 4, i2Str);
 	}
-	p += sprintf(p, "%c%c %16s %s\r\n", bpn, ipp, "", i2Str);
+	p += sprintf(p, "%c%c %16s %s%s", bpn, ipp, "", i2Str, LINE_SEPARATOR);
 	*asmrows = i1Str[0] ? 3 : 2;
     } else {
 xxx:
 	ipp = (ipGet(viewPid) == ofs) ? '>' : ' ';
-	(void)sprintf(line, "%c%c %s xxxxxxxx\r\n", bpn, ipp, buf);
+	(void)sprintf(line, "%c%c %s xxxxxxxx%s", bpn, ipp, buf, LINE_SEPARATOR);
 	*srcrows = 0;
 	*asmrows = 1;
     }
