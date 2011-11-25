$NetBSD: patch-src_tex2gif.cc,v 1.1 2011/11/25 21:38:09 joerg Exp $

--- src/tex2gif.cc.orig	2011-11-25 17:21:47.000000000 +0000
+++ src/tex2gif.cc
@@ -21,8 +21,8 @@
   Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
 
-#include <iostream.h>
-#include <fstream.h>
+#include <iostream>
+#include <fstream>
 #include <stdio.h>
 #include <string.h>
 
