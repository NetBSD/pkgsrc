$NetBSD: patch-exeloader.cc,v 1.1 2011/11/27 19:39:09 joerg Exp $

--- exeloader.cc.orig	2011-11-27 02:49:56.000000000 +0000
+++ exeloader.cc
@@ -18,6 +18,7 @@ with VMIPS; if not, write to the Free So
 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
 
 #include <string>
+#include <cstring>
 #include <cerrno>
 #include <cstdio>
 #include "vmips.h"
