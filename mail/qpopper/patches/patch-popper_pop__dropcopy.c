$NetBSD: patch-popper_pop__dropcopy.c,v 1.1 2024/10/11 06:46:55 nia Exp $

Include <fcntl.h> for open(2) and friends.

--- popper/pop_dropcopy.c.orig	2024-10-11 06:45:14.447164693 +0000
+++ popper/pop_dropcopy.c
@@ -169,6 +169,7 @@
 #include <stdlib.h>
 #include <ctype.h>
 #include <string.h>
+#include <fcntl.h>
 #include <flock.h>
 
 #include "config.h"
