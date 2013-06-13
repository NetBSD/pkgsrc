$NetBSD: patch-src_MLE.cc,v 1.1 2013/06/13 14:27:21 joerg Exp $

--- src/MLE.cc.orig	2013-06-12 19:41:35.000000000 +0000
+++ src/MLE.cc
@@ -22,10 +22,8 @@ along with this program; if not, write t
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */
 
-extern "C" {
 #include <R.h>
 #include <Rdefines.h>
-}
 #include <R_ext/Linpack.h>
 #include <math.h>  
 #include <stdio.h>  
