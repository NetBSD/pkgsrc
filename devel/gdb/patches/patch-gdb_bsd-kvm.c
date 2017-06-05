$NetBSD: patch-gdb_bsd-kvm.c,v 1.2 2017/06/05 11:38:51 maya Exp $

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
