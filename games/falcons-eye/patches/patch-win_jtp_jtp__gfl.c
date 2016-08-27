$NetBSD: patch-win_jtp_jtp__gfl.c,v 1.1 2016/08/27 20:59:47 joerg Exp $

--- win/jtp/jtp_gfl.c.orig	2016-07-02 11:12:12.000000000 +0000
+++ win/jtp/jtp_gfl.c
@@ -7,6 +7,7 @@
 
 #include "jtp_def.h"
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include "jtp_gra.h"
 #include "jtp_gfl.h"
