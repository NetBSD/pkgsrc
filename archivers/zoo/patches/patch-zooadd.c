$NetBSD: patch-zooadd.c,v 1.1 2014/06/29 03:24:33 dholland Exp $

use standard headers

--- zooadd.c~	1993-05-01 03:43:38.000000000 +0000
+++ zooadd.c
@@ -9,6 +9,7 @@ Copyright (C) 1986, 1987 Rahul Dhesi -- 
 (C) Copyright 1988 Rahul Dhesi -- All rights reserved
 (C) Copyright 1991 Rahul Dhesi -- All rights reserved
 */
+#include <unistd.h>
 #include "options.h"
 /* Adds files specified in parameter-list to archive zoo_path. */
 
