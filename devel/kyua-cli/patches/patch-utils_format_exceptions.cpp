$NetBSD: patch-utils_format_exceptions.cpp,v 1.1 2013/05/06 14:46:58 joerg Exp $

--- utils/format/exceptions.cpp.orig	2013-05-06 08:20:35.000000000 +0000
+++ utils/format/exceptions.cpp
@@ -26,6 +26,7 @@
 // (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 // OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
+#include <string>
 #include "utils/format/exceptions.hpp"
 
 using utils::format::bad_format_error;
