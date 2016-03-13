$NetBSD: patch-eventselect_eventselect.c,v 1.1 2016/03/13 09:06:01 dholland Exp $

Use standard headers.

--- eventselect/eventselect.c~	1998-09-28 20:26:18.000000000 +0000
+++ eventselect/eventselect.c
@@ -44,4 +44,5 @@ static char rcsid[] = "$Id: eventselect.
 #endif
 
+#include <stdlib.h>
 #include "nocol.h"
 #include <fcntl.h>		/* for O_RDONLY definition */
