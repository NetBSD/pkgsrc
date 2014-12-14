$NetBSD: patch-ext_tk_lib_tkextlib_tile_treeview.rb,v 1.1 2014/12/14 14:00:06 taca Exp $

* Add tcl/tk 8.6 support.

--- ext/tk/lib/tkextlib/tile/treeview.rb.orig	2009-10-02 10:45:39.000000000 +0000
+++ ext/tk/lib/tkextlib/tile/treeview.rb
@@ -986,6 +986,18 @@ class Tk::Tile::Treeview::Tag < TkObject
   end
   alias added? tag_has?
 
+  def tag_has
+    @t.tag_has(@id)
+  end
+
+  def add(*items)
+    @t.tag_add(@id, *items)
+  end
+
+  def remove(*items)
+    @t.tag_remove(@id, *items)
+  end
+
   def bind(seq, *args)
     if TkComm._callback_entry?(args[0]) || !block_given?
       cmd = args.shift
@@ -1299,6 +1311,24 @@ class Tk::Tile::Treeview < TkWindow
     _bindinfo([@path, 'tag', 'bind', tag], context)
   end
   alias tagbindinfo tag_bindinfo
+
+  def tag_names
+    tk_split_simplelist(tk_send('tag', 'names')).collect{|id|
+      Tk::Tile::Treeview::Tag.id2obj(self, id)
+    }
+  end
+
+  def tag_add(tag, *items)
+    fail ArgumentError, "no target items" if items.empty?
+    tk_send('tag', 'add', tagid(tag), *(items.collect{|item| tagid(item)}))
+    self
+  end
+
+  def tag_remove(tag, *items)
+    tk_send('tag', 'remove', tagid(tag), *(items.collect{|item| tagid(item)}))
+    self
+  end
+
 end
 
 #Tk.__set_toplevel_aliases__(:Ttk, Tk::Tile::Treeview, :TkTreeview)
