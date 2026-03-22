$NetBSD: patch-psbb_psbb.c,v 1.1 2026/03/22 10:34:03 nia Exp $

Fix implicit function declarations.

--- psbb/psbb.c.orig	2026-03-22 10:14:22.911015683 +0000
+++ psbb/psbb.c
@@ -18,6 +18,7 @@ with groff; see the file COPYING.  If no
 Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <errno.h>
 #ifndef errno
