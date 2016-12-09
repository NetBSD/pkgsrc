$NetBSD: patch-girara_internal.h,v 1.1 2016/12/09 08:06:50 leot Exp $

Update font handling for changes in Gtk+ 3.21
(from upstream commit 949c879aa84e9496fabc7d3602060e29f9dc42a1)

--- girara/internal.h.orig	2016-04-18 20:35:34.000000000 +0000
+++ girara/internal.h
@@ -148,6 +148,8 @@ HIDDEN bool girara_cmd_dump_config(girar
 HIDDEN bool girara_sc_feedkeys(girara_session_t* session, girara_argument_t* argument,
     girara_event_t* event, unsigned int t);
 
+HIDDEN void css_template_fill_font(GiraraTemplate* csstemplate, const char* font);
+
 /**
  * Structure of a command
  */
