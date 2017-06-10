$NetBSD: patch-core_mui_gtk__userlist.rb,v 1.1 2017/06/10 09:45:33 tsutsui Exp $

- pull upstream fixes for ticket #916
  https://dev.mikutter.hachune.net/issues/916

--- core/mui/gtk_userlist.rb.orig	2017-06-10 01:11:51.000000000 +0000
+++ core/mui/gtk_userlist.rb
@@ -27,6 +27,10 @@ class Gtk::UserList < Gtk::EventBox
     scrollbar = ::Gtk::VScrollbar.new(@listview.vadjustment)
     add Gtk::HBox.new(false, 0).add(@listview).closeup(scrollbar)
     @listview.ssc(:row_activated, &self.class.row_activated)
+    @listview.ssc(:expose_event){
+      emit_expose_user
+      false
+    }
   end
 
   def each
@@ -68,5 +72,25 @@ class Gtk::UserList < Gtk::EventBox
     @listview.reorder(user)
     self end
 
+  private
+
+  def emit_expose_user
+    if @listview.visible_range
+      current, last = @listview.visible_range
+      Enumerator.new{|y|
+        while (current <=> last) < 1
+          y << @listview.model.get_iter(current)
+          break if not current.next!
+        end
+      }.reject{|iter|
+        iter[Gtk::InnerUserList::COL_ICON]
+      }.each do |iter|
+        iter[Gtk::InnerUserList::COL_ICON] = iter[Gtk::InnerUserList::COL_USER].icon.load_pixbuf(width: 24, height: 24){|pixbuf|
+          iter[Gtk::InnerUserList::COL_ICON] = pixbuf unless @listview.destroyed?
+        }
+      end
+    end
+  end
+
 end
 
