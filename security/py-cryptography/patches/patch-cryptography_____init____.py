$NetBSD: patch-cryptography_____init____.py,v 1.1 2014/03/21 22:04:19 wiz Exp $

Fix use with python-2.x.

--- cryptography/__init__.py.orig	2014-03-04 00:51:26.000000000 +0000
+++ cryptography/__init__.py
@@ -10,6 +10,9 @@
 # implied.
 # See the License for the specific language governing permissions and
 # limitations under the License.
+
+from __future__ import absolute_import, division, print_function
+
 from cryptography.__about__ import (
     __title__, __summary__, __uri__, __version__, __author__, __email__,
     __license__, __copyright__
