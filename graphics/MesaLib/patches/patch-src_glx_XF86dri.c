$NetBSD: patch-src_glx_XF86dri.c,v 1.1 2013/12/12 14:44:10 is Exp $

--- src/glx/XF86dri.c.orig	2010-10-19 17:58:29.000000000 +0000
+++ src/glx/XF86dri.c
@@ -43,6 +43,7 @@ SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 #include <X11/extensions/Xext.h>
 #include <X11/extensions/extutil.h>
 #include "xf86dristr.h"
+#include <limits.h>
 
 static XExtensionInfo _xf86dri_info_data;
 static XExtensionInfo *xf86dri_info = &_xf86dri_info_data;
@@ -201,7 +202,11 @@ XF86DRIOpenConnection(Display * dpy, int screen, drm_handle_t * hSAREA,
    }
 
    if (rep.length) {
-      if (!(*busIdString = (char *) Xcalloc(rep.busIdStringLength + 1, 1))) {
+      if (rep.busIdStringLength < INT_MAX)
+         *busIdString = (char *) Xcalloc(rep.busIdStringLength + 1, 1);
+      else
+         *busIdString = NULL;
+      if (*busIdString == NULL) {
          _XEatData(dpy, ((rep.busIdStringLength + 3) & ~3));
          UnlockDisplay(dpy);
          SyncHandle();
@@ -300,9 +301,11 @@ XF86DRIGetClientDriverName(Display * dpy
    *ddxDriverPatchVersion = rep.ddxDriverPatchVersion;
 
    if (rep.length) {
-      if (!
-          (*clientDriverName =
-           (char *) Xcalloc(rep.clientDriverNameLength + 1, 1))) {
+      if (rep.clientDriverNameLength < INT_MAX)
+         *clientDriverName = (char *) Xcalloc(rep.clientDriverNameLength + 1, 1);
+      else
+         *clientDriverName = NULL;
+      if (*clientDriverName == NULL) {
          _XEatData(dpy, ((rep.clientDriverNameLength + 3) & ~3));
          UnlockDisplay(dpy);
          SyncHandle();
