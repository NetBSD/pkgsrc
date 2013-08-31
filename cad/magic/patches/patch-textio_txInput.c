$NetBSD: patch-textio_txInput.c,v 1.1 2013/08/31 14:44:30 joerg Exp $

--- textio/txInput.c.orig	2013-08-31 13:22:53.000000000 +0000
+++ textio/txInput.c
@@ -27,7 +27,7 @@ static char rcsid[] __attribute__ ((unus
 #include <unistd.h>
 #include <ctype.h>
 #include <dirent.h>
-
+#include <termios.h>
 
 #include "utils/magsgtty.h"
 #include "utils/magic.h"
