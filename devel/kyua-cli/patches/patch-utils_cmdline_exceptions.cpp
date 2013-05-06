$NetBSD: patch-utils_cmdline_exceptions.cpp,v 1.1 2013/05/06 14:46:58 joerg Exp $

--- utils/cmdline/exceptions.cpp.orig	2013-05-06 08:19:49.000000000 +0000
+++ utils/cmdline/exceptions.cpp
@@ -26,6 +26,7 @@
 // (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 // OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
+#include <string>
 #include "utils/cmdline/exceptions.hpp"
 
 #include "utils/format/macros.hpp"
