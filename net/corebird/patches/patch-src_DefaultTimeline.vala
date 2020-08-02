$NetBSD: patch-src_DefaultTimeline.vala,v 1.1 2020/08/02 22:15:05 mef Exp $

DefaultTimeline.vala:50.3-50.24: error: Creation method of abstract class cannot be public.
  public DefaultTimeline (int id) {
  ^^^^^^^^^^^^^^^^^^^^^^
Compilation failed: 1 error(s), 0 warning(s)

--- src/DefaultTimeline.vala.orig	2018-03-01 18:54:45.000000000 +0000
+++ src/DefaultTimeline.vala
@@ -47,7 +47,7 @@ public abstract class DefaultTimeline : 
   private double last_value = 0.0;
 
 
-  public DefaultTimeline (int id) {
+  protected DefaultTimeline (int id) {
     this.id = id;
     this.hscrollbar_policy = Gtk.PolicyType.NEVER;
     this.scrolled_to_start.connect (handle_scrolled_to_start);
