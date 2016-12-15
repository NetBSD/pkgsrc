$NetBSD: patch-gtk2__ardour_startup.cc,v 1.1 2016/12/15 23:45:07 joerg Exp $

Use bool conversion, RefPtr doesn't compare to 0 in C++11 mode.

--- gtk2_ardour/startup.cc.orig	2016-12-15 17:23:30.130893869 +0000
+++ gtk2_ardour/startup.cc
@@ -79,23 +79,23 @@ ArdourStartup::ArdourStartup ()
 	set_position (WIN_POS_CENTER);
 	set_border_width (12);
 
-	if ((icon_pixbuf = ::get_icon ("ardour_icon_48px")) == 0) {
+	if (!(icon_pixbuf = ::get_icon ("ardour_icon_48px"))) {
 		throw failed_constructor();
 	}
 
 	list<Glib::RefPtr<Gdk::Pixbuf> > window_icons;
 	Glib::RefPtr<Gdk::Pixbuf> icon;
 
-	if ((icon = ::get_icon ("ardour_icon_16px")) != 0) {
+	if ((icon = ::get_icon ("ardour_icon_16px"))) {
 		window_icons.push_back (icon);
 	}
-	if ((icon = ::get_icon ("ardour_icon_22px")) != 0) {
+	if ((icon = ::get_icon ("ardour_icon_22px"))) {
 		window_icons.push_back (icon);
 	}
-	if ((icon = ::get_icon ("ardour_icon_32px")) != 0) {
+	if ((icon = ::get_icon ("ardour_icon_32px"))) {
 		window_icons.push_back (icon);
 	}
-	if ((icon = ::get_icon ("ardour_icon_48px")) != 0) {
+	if ((icon = ::get_icon ("ardour_icon_48px"))) {
 		window_icons.push_back (icon);
 	}
 	if (!window_icons.empty ()) {
