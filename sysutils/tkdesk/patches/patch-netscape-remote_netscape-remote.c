$NetBSD: patch-netscape-remote_netscape-remote.c,v 1.1 2022/06/06 05:11:58 dholland Exp $

Use standard headers.

--- netscape-remote/netscape_remote.c~	2004-02-29 21:52:24.000000000 +0000
+++ netscape-remote/netscape_remote.c
@@ -31,6 +31,7 @@ static char rcsid[]=
 #include "config.h"
 #include <sys/types.h>
 #include <unistd.h>
+#include <string.h>
 #ifdef HAVE_TCL8_0_H
 #include <tcl8.0.h>
 #include <tk8.0.h>
