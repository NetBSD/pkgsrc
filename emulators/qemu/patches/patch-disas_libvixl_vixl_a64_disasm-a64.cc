$NetBSD: patch-disas_libvixl_vixl_a64_disasm-a64.cc,v 1.1 2017/02/27 05:19:29 adam Exp $

Re-order includes, so __STDC_CONSTANT_MACROS gets defined before including stdint.h.

--- disas/libvixl/vixl/a64/disasm-a64.cc.orig	2017-02-26 09:56:59.312135262 +0000
+++ disas/libvixl/vixl/a64/disasm-a64.cc
@@ -24,8 +24,8 @@
 // OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 // OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
-#include <cstdlib>
 #include "vixl/a64/disasm-a64.h"
+#include <cstdlib>
 
 namespace vixl {
 
