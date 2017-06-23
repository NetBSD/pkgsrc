$NetBSD: patch-gdb_bsd-kvm.c,v 1.3 2017/06/23 19:49:20 kamil Exp $

need _KMEMUSER to use some headers on netbsd, else vaddr_t
is undefined.

--- gdb/bsd-kvm.c.orig	2017-06-04 15:51:26.000000000 +0000
+++ gdb/bsd-kvm.c
@@ -17,6 +17,7 @@
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
 
+#define _KMEMUSER 1
 #include "defs.h"
 #include "cli/cli-cmds.h"
 #include "command.h"
@@ -36,7 +37,9 @@
 #include "readline/readline.h"
 #include <sys/param.h>
 #include <sys/proc.h>
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/user.h>
+#endif
 
 #include "bsd-kvm.h"
 
