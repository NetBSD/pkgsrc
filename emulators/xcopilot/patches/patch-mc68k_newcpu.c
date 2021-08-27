$NetBSD: patch-mc68k_newcpu.c,v 1.1 2021/08/27 03:41:41 ryoon Exp $

* Include string.h for strlen().

--- mc68k/newcpu.c.orig	1998-07-14 03:54:27.000000000 +0000
+++ mc68k/newcpu.c
@@ -35,6 +35,7 @@ Update History:   (most recent first)
 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 
 #include "sysdeps.h"
 #include "shared.h"
