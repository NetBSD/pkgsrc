$NetBSD: patch-src_getNset.cc,v 1.1 2013/06/13 14:27:21 joerg Exp $

--- src/getNset.cc.orig	2013-06-12 19:43:18.000000000 +0000
+++ src/getNset.cc
@@ -23,10 +23,8 @@ along with this program; if not, write t
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */
 
-extern "C" {
 #include <R.h>
 #include <Rdefines.h>
-}
 #include <math.h>  
 #include <stdio.h>  
 #include <stdlib.h>
