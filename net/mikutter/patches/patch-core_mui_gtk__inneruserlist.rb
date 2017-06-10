$NetBSD: patch-core_mui_gtk__inneruserlist.rb,v 1.1 2017/06/10 09:45:33 tsutsui Exp $

- pull upstream fixes for ticket #916
  https://dev.mikutter.hachune.net/issues/916

--- core/mui/gtk_inneruserlist.rb.orig	2017-06-10 01:11:51.000000000 +0000
+++ core/mui/gtk_inneruserlist.rb
@@ -32,10 +32,10 @@ class Gtk::InnerUserList < Gtk::TreeView
     }.reject{|user|
       exist_users.include?(user)
     }.deach{|user|
+      break if destroyed?
       iter = model.append
-      iter[COL_ICON] = user.icon.load_pixbuf(width: 24, height: 24){|pixbuf|
-        iter[COL_ICON] = pixbuf unless destroyed?
-      }
+      # ここではCOL_ICONを埋めず、nilのままにしてアイコンを表示しない。
+      # アイコンは Gtk::UserList#emit_expose_user で、カラムが表示された時に初めて埋める
       iter[COL_SCREEN_NAME] = user[:idname]
       iter[COL_NAME] = user[:name]
       iter[COL_USER] = user
