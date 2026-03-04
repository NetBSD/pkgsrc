$NetBSD: patch-font_font__peer__x11.cc,v 1.1 2026/03/04 10:27:19 tsutsui Exp $

- appease -Wwrite-strings warnings

--- font/font_peer_x11.cc.orig	2026-03-03 20:57:59.750955737 +0000
+++ font/font_peer_x11.cc
@@ -212,7 +212,7 @@ void PeerX11::InitDisplay(Display* _d) {
 void PeerX11::OpenDisplay(void) {
 	if (display) return;
 
-	char* display_name = getenv("DISPLAY");
+	const char* display_name = getenv("DISPLAY");
 	if (display_name == 0) display_name = ":0";
 
 	display = XOpenDisplay(display_name);
