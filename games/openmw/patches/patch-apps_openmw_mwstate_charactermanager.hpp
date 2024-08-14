$NetBSD: patch-apps_openmw_mwstate_charactermanager.hpp,v 1.1 2024/08/14 07:25:37 nia Exp $

Add missing include for std::list.

--- apps/openmw/mwstate/charactermanager.hpp.orig	2024-08-14 06:58:47.296944113 +0000
+++ apps/openmw/mwstate/charactermanager.hpp
@@ -2,6 +2,7 @@
 #define GAME_STATE_CHARACTERMANAGER_H
 
 #include <boost/filesystem/path.hpp>
+#include <list>
 
 #include "character.hpp"
 
