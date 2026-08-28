$NetBSD: patch-pcmanfm_desktopwindow.cpp,v 1.1 2026/08/28 03:56:08 gutteridge Exp $

Temporarily revert a Wayland-only change that requires a newer version
of plasma6-layer-shell-qt than pkgsrc carries.

--- pcmanfm/desktopwindow.cpp.orig	2026-08-26 15:41:04.000000000 +0000
+++ pcmanfm/desktopwindow.cpp
@@ -214,16 +214,6 @@ DesktopWindow::DesktopWindow(int screenNum, const QStr
                 layershell->setKeyboardInteractivity(LayerShellQt::Window::KeyboardInteractivityOnDemand);
                 layershell->setExclusiveZone(-1); // not moved to accommodate for other surfaces
                 layershell->setScope(QStringLiteral("desktop")); // just for distinguishing it
-
-                auto screen = getDesktopScreen();
-                if(screen != nullptr) {
-                    win->setScreen(screen);
-                    layershell->setWantsToBeOnActiveScreen(false);
-                    layershell->setScreen(nullptr);
-                }
-                else {
-                    layershell->setWantsToBeOnActiveScreen(true);
-                }
             }
         }
     }
