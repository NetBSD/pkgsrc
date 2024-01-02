$NetBSD: patch-Pixmap.c,v 1.1 2024/01/02 20:41:47 nros Exp $

Fix implicit funvtion declaration of exit

--- Pixmap.c.orig	2024-01-02 09:18:23.243143182 +0000
+++ Pixmap.c
@@ -67,6 +67,7 @@ static char rcsid[] = "$Id: Pixmap.c,v 1
 #include "PixmapP.h"
     
 #include <stdio.h>
+#include <stdlib.h>
 #include <math.h>
 
 #define XtStrlen(s)                   ((s) ? strlen(s) : 0)
