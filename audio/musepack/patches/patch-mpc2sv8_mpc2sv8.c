$NetBSD: patch-mpc2sv8_mpc2sv8.c,v 1.1 2026/03/16 12:15:01 nia Exp $

Fix implicit function declarations.

--- mpc2sv8/mpc2sv8.c.orig	2026-03-16 12:07:25.431420797 +0000
+++ mpc2sv8/mpc2sv8.c
@@ -32,6 +32,7 @@
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 #include <stdio.h>
+#include <string.h>
 #include <mpc/mpcdec.h>
 #include <mpc/minimax.h>
 #include <getopt.h>
