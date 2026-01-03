$NetBSD: patch-src_web_edit__load.cc,v 1.1 2026/01/03 10:28:11 wiz Exp $

Fix build with fmtlib 12.

--- src/web/edit_load.cc.orig	2026-01-03 10:17:26.553925116 +0000
+++ src/web/edit_load.cc
@@ -80,7 +80,7 @@ void Web::EditLoad::process()
 
     if (obj->getMTime() > std::chrono::seconds::zero()) {
         auto lmtEl = item.append_child("last_modified");
-        lmtEl.append_attribute("value") = fmt::format("{:%Y-%m-%d %H:%M:%S}", fmt::localtime(obj->getMTime().count())).c_str();
+        lmtEl.append_attribute("value") = grbLocaltime("{:%Y-%m-%d %H:%M:%S}", obj->getMTime());
         lmtEl.append_attribute("editable") = false;
     } else {
         auto lmtEl = item.append_child("last_modified");
@@ -90,7 +90,7 @@ void Web::EditLoad::process()
 
     if (obj->getUTime() > std::chrono::seconds::zero()) {
         auto lmtEl = item.append_child("last_updated");
-        lmtEl.append_attribute("value") = fmt::format("{:%Y-%m-%d %H:%M:%S}", fmt::localtime(obj->getUTime().count())).c_str();
+        lmtEl.append_attribute("value") = grbLocaltime("{:%Y-%m-%d %H:%M:%S}", obj->getUTime());
         lmtEl.append_attribute("editable") = false;
     } else {
         auto lmtEl = item.append_child("last_updated");
@@ -222,7 +222,7 @@ void Web::EditLoad::process()
 
             metaEntry = metaData.append_child("metadata");
             metaEntry.append_attribute("metaname") = fmt::format("upnp:lastPlaybackTime@group[{}]", playStatus->getGroup()).c_str();
-            metaEntry.append_attribute("metavalue") = fmt::format("{:%Y-%m-%d T %H:%M:%S}", fmt::localtime(playStatus->getLastPlayed().count())).c_str();
+            metaEntry.append_attribute("metavalue") = grbLocaltime("{:%Y-%m-%d T %H:%M:%S}", playStatus->getLastPlayed());
             metaEntry.append_attribute("editable") = false;
 
             if (playStatus->getLastPlayedPosition() > std::chrono::seconds::zero()) {
