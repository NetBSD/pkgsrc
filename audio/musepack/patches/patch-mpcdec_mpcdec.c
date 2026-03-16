$NetBSD: patch-mpcdec_mpcdec.c,v 1.1 2026/03/16 12:15:02 nia Exp $

Fix implicit function declarations.

--- mpcdec/mpcdec.c.orig	2026-03-16 12:07:42.587535306 +0000
+++ mpcdec/mpcdec.c
@@ -32,6 +32,7 @@
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 #include <stdio.h>
+#include <string.h>
 #include <assert.h>
 #include <time.h>
 #include <mpc/mpcdec.h>
