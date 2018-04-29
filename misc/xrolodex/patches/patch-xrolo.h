$NetBSD: patch-xrolo.h,v 1.1 2018/04/29 03:56:08 dholland Exp $

Use correct includes, fixing LP64 issues (see PR 52248)

--- xrolo.h~	1996-01-30 23:36:29.000000000 +0000
+++ xrolo.h
@@ -36,6 +36,7 @@ See these modules for more details.
 #include <Xm/RowColumn.h>
 #include <Xm/Separator.h>
 #include <Xm/Protocols.h>
+#include <Xm/FileSB.h>                        
 
 #include "ctrlpanel.h"
 #include "listshell.h"
