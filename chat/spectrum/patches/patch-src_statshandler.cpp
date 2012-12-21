$NetBSD: patch-src_statshandler.cpp,v 1.1 2012/12/21 00:10:59 schnoebe Exp $

Force the seconds of uptime to be an integer quantity.

Shouldn't cause a problem, as I doubt any system will be ever be up for
30+ years, so representing in a signed, potentially 32 bit quantity
shouldn't be a problem.

--- src/statshandler.cpp.orig	2011-06-11 13:17:44.000000000 +0000
+++ src/statshandler.cpp
@@ -172,7 +172,12 @@ Tag* GlooxStatsHandler::handleTag (Tag *
 				t = new Tag("stat");
 				t->addAttribute("name","uptime");
 				t->addAttribute("units","seconds");
-				t->addAttribute("value",seconds - m_startTime);
+				// no more than integer number of seconds
+				// of uptime (NetBSD 6.0 and later have time_t
+				// as a 64 bit qauntity, but I doubt any single
+				// system will ever be up 30 years, so an int
+				// (32 bits on some platforms) should suffice)
+				t->addAttribute("value", (int)(seconds - m_startTime));
 				query->addChild(t);
 			} else if (name == "users/registered") {
 				t = new Tag("stat");
