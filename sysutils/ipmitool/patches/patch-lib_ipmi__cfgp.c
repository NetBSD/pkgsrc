$NetBSD: patch-lib_ipmi__cfgp.c,v 1.1 2018/01/08 22:37:57 jperkin Exp $

Spell stdlib.h correctly.

--- lib/ipmi_cfgp.c.orig	2016-08-21 06:59:27.000000000 +0000
+++ lib/ipmi_cfgp.c
@@ -30,7 +30,7 @@
  * POSSIBILITY OF SUCH DAMAGE.
  */
 
-#include <malloc.h>
+#include <stdlib.h>
 #include <string.h>
 
 #include <ipmitool/helper.h>
