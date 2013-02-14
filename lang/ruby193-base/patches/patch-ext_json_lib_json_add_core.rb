$NetBSD: patch-ext_json_lib_json_add_core.rb,v 1.1.2.2 2013/02/14 14:58:51 tron Exp $

Fix for CVE-2013-0269.

--- ext/json/lib/json/add/core.rb.orig	2011-08-31 07:02:52.000000000 +0000
+++ ext/json/lib/json/add/core.rb
@@ -36,8 +36,8 @@ class Time
     if usec = object.delete('u') # used to be tv_usec -> tv_nsec
       object['n'] = usec * 1000
     end
-    if respond_to?(:tv_nsec)
-      at(*object.values_at('s', 'n'))
+    if instance_methods.include?(:tv_nsec)
+      at(object['s'], Rational(object['n'], 1000))
     else
       at(object['s'], object['n'] / 1000)
     end
@@ -46,10 +46,13 @@ class Time
   # Returns a hash, that will be turned into a JSON object and represent this
   # object.
   def as_json(*)
+    nanoseconds = [ tv_usec * 1000 ]
+    respond_to?(:tv_nsec) and nanoseconds << tv_nsec
+    nanoseconds = nanoseconds.max
     {
       JSON.create_id => self.class.name,
       's'            => tv_sec,
-      'n'            => respond_to?(:tv_nsec) ? tv_nsec : tv_usec * 1000
+      'n'            => nanoseconds,
     }
   end
 
