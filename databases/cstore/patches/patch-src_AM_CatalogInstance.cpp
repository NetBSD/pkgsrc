$NetBSD: patch-src_AM_CatalogInstance.cpp,v 1.1 2011/12/20 13:42:47 wiz Exp $

Add missing header.

--- src/AM/CatalogInstance.cpp.orig	2006-10-18 06:05:29.000000000 +0000
+++ src/AM/CatalogInstance.cpp
@@ -29,6 +29,7 @@
  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 #include <iostream>
+#include <stdlib.h>
 #include "CatalogInstance.h"
 #include "CatalogInstanceBDB.h"
 
