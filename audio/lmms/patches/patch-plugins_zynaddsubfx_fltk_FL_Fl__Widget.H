$NetBSD: patch-plugins_zynaddsubfx_fltk_FL_Fl__Widget.H,v 1.1 2013/06/27 15:48:11 joerg Exp $

--- plugins/zynaddsubfx/fltk/FL/Fl_Widget.H.orig	2013-06-27 13:20:50.000000000 +0000
+++ plugins/zynaddsubfx/fltk/FL/Fl_Widget.H
@@ -160,6 +160,7 @@ protected:
   /** flags possible values enumeration.
       See activate(), output(), visible(), changed(), set_visible_focus()
   */
+public:
   enum {
         INACTIVE        = 1<<0,   ///< the widget can't receive focus, and is disabled but potentially visible
         INVISIBLE       = 1<<1,   ///< the widget is not drawn, but can receive a few special events
@@ -184,6 +185,7 @@ protected:
         USERFLAG2       = 1<<30,  ///< reserved for 3rd party extensions
         USERFLAG1       = 1<<31   ///< reserved for 3rd party extensions
   };
+protected:
   void draw_box() const;
   void draw_box(Fl_Boxtype t, Fl_Color c) const;
   void draw_box(Fl_Boxtype t, int x,int y,int w,int h, Fl_Color c) const;
