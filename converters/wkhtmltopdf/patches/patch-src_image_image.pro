$NetBSD: patch-src_image_image.pro,v 1.3 2023/01/20 16:26:56 manu Exp $

--- src/image/image.pro.orig	2017-09-10 15:04:52.049437840 +0000
+++ src/image/image.pro
@@ -15,6 +15,8 @@
 # You should have received a copy of the GNU Lesser General Public License
 # along with wkhtmltopdf.  If not, see <http:#www.gnu.org/licenses/>.
 
+LIBS+= ${COMPILER_RPATH_FLAG}${X11BASE}/lib ${COMPILER_RPATH_FLAG}${PREFIX}/lib
+
 include(../../common.pri)
 
 TEMPLATE = app
@@ -47,4 +49,6 @@
 }
 
 # Input
 SOURCES += wkhtmltoimage.cc imagearguments.cc imagecommandlineparser.cc imagedocparts.cc
+
+LIBS += -lcrypto -lssl
