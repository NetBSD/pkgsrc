$NetBSD: patch-src_upnp_xml__builder.cc,v 1.1 2026/01/03 10:28:11 wiz Exp $

Fix build with fmtlib 12.

--- src/upnp/xml_builder.cc.orig	2026-01-03 10:23:20.003405707 +0000
+++ src/upnp/xml_builder.cc
@@ -451,7 +451,7 @@ void UpnpXMLBuilder::renderObject(
         auto playStatus = item->getPlayStatus();
         if (playStatus) {
             auxData[UPNP_SEARCH_PLAY_COUNT] = fmt::format("{}", playStatus->getPlayCount());
-            auxData[UPNP_SEARCH_LAST_PLAYED] = fmt::format("{:%Y-%m-%d T %H:%M:%S}", fmt::localtime(playStatus->getLastPlayed().count()));
+            auxData[UPNP_SEARCH_LAST_PLAYED] = grbLocaltime("{:%Y-%m-%dT%H:%M:%S}", playStatus->getLastPlayed());
             auxData["upnp:lastPlaybackPosition"] = fmt::format("{}", millisecondsToHMSF(playStatus->getLastPlayedPosition().count()));
             propNames.push_back(addField(result, objFilter, UPNP_SEARCH_PLAY_COUNT, auxData[UPNP_SEARCH_PLAY_COUNT]));
             propNames.push_back(addField(result, objFilter, UPNP_SEARCH_LAST_PLAYED, auxData[UPNP_SEARCH_LAST_PLAYED]));
@@ -487,7 +487,7 @@ void UpnpXMLBuilder::renderObject(
     // make sure a date is set
     auto dateNode = result.child(DC_DATE);
     if (!dateNode) {
-        auto fDate = fmt::format("{:%FT%T%z}", fmt::localtime(obj->getMTime().count()));
+        auto fDate = grbLocaltime("{:%FT%T%z}", obj->getMTime());
         if (simpleDate)
             fDate = makeSimpleDate(fDate);
         result.append_child(DC_DATE).append_child(pugi::node_pcdata).set_value(fDate.c_str());
