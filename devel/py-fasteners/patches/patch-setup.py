$NetBSD: patch-setup.py,v 1.1 2021/02/15 14:18:35 mef Exp $

py36 gives following flag:
UnicodeDecodeError: 'ascii' codec can't decode byte 0xf0 in position 429: ordinal not in range(128)

--- setup.py.orig	2020-12-17 03:03:32.000000000 +0900
+++ setup.py	2021-02-15 23:09:28.515008318 +0900
@@ -18,10 +18,11 @@
 #    License for the specific language governing permissions and limitations
 #    under the License.
 
+import sys
 from setuptools import find_packages
 from setuptools import setup
 
-with open("README.md", "r") as readme:
+with open("README.md", **({'encoding': 'UTF-8'} if sys.version_info.major>=3 else {})) as readme:
     long_description = readme.read()
 
 install_requires = [
