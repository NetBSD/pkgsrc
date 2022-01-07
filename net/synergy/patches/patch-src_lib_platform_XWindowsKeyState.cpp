$NetBSD: patch-src_lib_platform_XWindowsKeyState.cpp,v 1.1 2022/01/07 23:02:48 tnn Exp $

make dbus optional

--- src/lib/platform/XWindowsKeyState.cpp.orig	2021-11-22 13:50:34.000000000 +0000
+++ src/lib/platform/XWindowsKeyState.cpp
@@ -16,7 +16,7 @@
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */
 
-#ifndef __APPLE__
+#ifdef WITH_DBUS
 #include <QtDBus>
 #endif
 
@@ -249,6 +249,7 @@ XWindowsKeyState::getKeyMap(synergy::Key
     updateKeysymMap(keyMap);
 }
 
+#if 0
 bool XWindowsKeyState::setCurrentLanguageWithDBus(SInt32 group) const
 {
     QString service = "org.gnome.Shell";
@@ -289,6 +290,7 @@ bool XWindowsKeyState::setCurrentLanguag
 
     return true;
 }
+#endif
 
 void
 XWindowsKeyState::fakeKey(const Keystroke& keystroke)
@@ -321,7 +323,7 @@ XWindowsKeyState::fakeKey(const Keystrok
         if (keystroke.m_data.m_group.m_absolute) {
             LOG((CLOG_WARN "LANGUAGE_DEBUG  group %d", keystroke.m_data.m_group.m_group));
 
-#ifndef __APPLE__
+#ifdef WITH_DBUS
             if(setCurrentLanguageWithDBus(keystroke.m_data.m_group.m_group)) {
                 break;
             }
@@ -342,7 +344,7 @@ XWindowsKeyState::fakeKey(const Keystrok
         else {
             LOG((CLOG_WARN "LANGUAGE_DEBUG  group %+d", keystroke.m_data.m_group.m_group));
 
-#ifndef __APPLE__
+#ifdef WITH_DBUS
             if(setCurrentLanguageWithDBus(keystroke.m_data.m_group.m_group)) {
                 break;
             }
