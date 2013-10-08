$NetBSD: patch-libfreerdp-core_tcp.c,v 1.1 2013/10/08 12:31:22 obache Exp $

* config is used in indirect included header files.

--- libfreerdp-core/tcp.c.orig	2013-01-02 21:46:59.000000000 +0000
+++ libfreerdp-core/tcp.c
@@ -18,6 +18,8 @@
  * limitations under the License.
  */
 
+#include "config.h"
+
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
