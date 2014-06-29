$NetBSD: patch-zoo.c,v 1.1 2014/06/29 03:24:33 dholland Exp $

use standard headers

--- zoo.c~	1991-07-17 12:28:43.000000000 +0000
+++ zoo.c
@@ -15,6 +15,7 @@ Copyright (C) 1986, 1987 Rahul Dhesi -- 
 (C) Copyright 1988 Rahul Dhesi -- All rights reserved
 (C) Copyright 1991 Rahul Dhesi -- All rights reserved
 */
+#include <unistd.h>
 #include "options.h"
 #include "zooio.h"
 #include "various.h"
