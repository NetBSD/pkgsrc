$NetBSD: patch-core_lib_mikutwitter_api__shortcuts.rb,v 1.1 2017/06/10 09:45:33 tsutsui Exp $

- pull upstream fixes for ticket #916
  https://dev.mikutter.hachune.net/issues/916

--- core/lib/mikutwitter/api_shortcuts.rb.orig	2017-06-10 01:11:51.000000000 +0000
+++ core/lib/mikutwitter/api_shortcuts.rb
@@ -52,10 +52,10 @@ module MikuTwitter::APIShortcuts
   defcursorpager :followers_id, 'followers/ids', :paged_ids, :ids, id: :user_id
 
   def followings(args = {})
-    idlist2userlist(friends_id(RELATIONAL_DEFAULT.merge(args))) end
+    idlist2userlist(friends_id(RELATIONAL_DEFAULT.merge(args)), cache: args[:cache]) end
 
   def followers(args = {})
-    idlist2userlist(followers_id(RELATIONAL_DEFAULT.merge(args))) end
+    idlist2userlist(followers_id(RELATIONAL_DEFAULT.merge(args)), cache: args[:cache]) end
 
   def direct_messages(args = {})
     (self/:direct_messages).direct_messages({:count => 200}.merge(args)) end
@@ -258,21 +258,30 @@ module MikuTwitter::APIShortcuts
         cursor_pager(api, parser, key, args.merge(cursor: res[:next_cursor])).next{ |nex|
           res[key] + nex } end } end
 
-  def idlist2userlist(deferred)
-    deferred.next{ |ids|
-      promise = Deferred.new(true)
-      Thread.new{
-        begin
-          promise.call(User.findbyid(ids))
-        rescue Exception => e
-          promise.fail(e) end }
-      promise.next{ |users|
-        if(users.size != ids.size)
-          Deferred.when(*(ids - users.map{ |u| u[:id] }).each_slice(100).map{ |segment|
-                          user_lookup(id: segment.join(',')).trap{ |e| warn e; [] } }).next{ |res|
-            res.inject(users){ |a, b| a + b } }
+  def idlist2userlist(deferred, cache: :keep)
+    deferred.next do |ids|
+      detected = {}           # {id => User}
+      lookups = Set.new       # [id]
+      ids.each do |id|
+        user = User.findbyid(id, Retriever::DataSource::USE_LOCAL_ONLY)
+        if user.is_a? User
+          detected[id] = user
         else
-          users end } } end
+          lookups << id
+        end
+      end
+      defer = lookups.each_slice(100).map{|lookup_chunk|
+        user_lookup(id: lookup_chunk.join(','), cache: cache).next{|users|
+          users.each do |user|
+            detected[user.id] = user
+          end
+        }
+      }
+      Delayer::Deferred.when(*defer).next do
+        ids.map{|id| detected[id] }
+      end
+    end
+  end
 
   # upload.twitter.comに画像等をアップロードし、
   # アップロードしたファイルのmedia_idを返す。
