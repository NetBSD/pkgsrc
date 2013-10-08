$NetBSD: patch-libfreerdp-core_listener.c,v 1.1 2013/10/08 12:31:22 obache Exp $

* config is used in indirect included header files.

--- libfreerdp-core/listener.c.orig	2013-01-02 21:46:59.000000000 +0000
+++ libfreerdp-core/listener.c
@@ -17,6 +17,8 @@
  * limitations under the License.
  */
 
+#include "config.h"
+
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
