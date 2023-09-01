$NetBSD: patch-include_assimp_Hash.h,v 1.1 2023/09/01 10:39:06 nia Exp $

Include cstdlib for abs(3). Fixes a build failure on NetBSD 8.

--- include/assimp/Hash.h.orig	2022-09-08 18:13:43.000000000 +0000
+++ include/assimp/Hash.h
@@ -48,6 +48,7 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 
 #include <stdint.h>
 #include <string.h>
+#include <cstdlib>
 #include <cmath>
 
 // ------------------------------------------------------------------------------------------------
