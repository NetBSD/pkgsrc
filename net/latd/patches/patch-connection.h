$NetBSD: patch-connection.h,v 1.1 2011/11/25 22:14:17 joerg Exp $

--- connection.h.orig	2011-11-25 19:19:54.000000000 +0000
+++ connection.h
@@ -12,6 +12,7 @@
     GNU General Public License for more details.
 ******************************************************************************/
 
+#include <cstring>
 
 class LATConnection
 {
