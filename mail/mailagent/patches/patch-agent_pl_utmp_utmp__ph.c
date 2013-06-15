$NetBSD: patch-agent_pl_utmp_utmp__ph.c,v 1.1 2013/06/15 06:09:37 obache Exp $

--- agent/pl/utmp/utmp_ph.c.orig	2001-03-17 18:31:28.000000000 +0000
+++ agent/pl/utmp/utmp_ph.c
@@ -50,6 +50,8 @@
 #include <strings.h>
 #endif
 
+#include <stdio.h>
+#include <stdlib.h>
 #include <utmp.h>
 #include "confmagic.h"
 
