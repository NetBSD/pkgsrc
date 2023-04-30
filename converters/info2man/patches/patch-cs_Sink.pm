$NetBSD: patch-cs_Sink.pm,v 1.1 2023/04/30 14:07:04 nikita Exp $

Eliminate old-fashioned call for flush.pl

--- cs/Sink.pm.orig	2003-01-18 23:34:22.000000000 +0000
+++ cs/Sink.pm
@@ -66,7 +66,7 @@ use strict qw(vars);
 use cs::Misc;
 use cs::IO;
 
-require 'flush.pl';
+# require 'flush.pl';
 
 package cs::Sink;
 
@@ -150,7 +150,13 @@ Flushes any pending output in I<handle> 
 
   if ($type eq FILE)
   { my($FILE)=shift;
-    ::flush($FILE);
+    # ::flush($FILE);
+    my $old_file;
+    $old_file = select($FILE);
+    $| = 1;
+    print "";
+    $| = 0;
+    select($old_file);
     $this->{IO}=($cs::Sink::_UseIO
 		  ? new_from_fd IO::Handle (fileno($FILE),"w")
 		  : $FILE);
@@ -448,7 +454,13 @@ sub Flush
 
   if ($type eq FILE)
   {
-    ::flush($this->{IO});
+    # ::flush($this->{IO});
+    my $old_file;
+    $old_file = select($this->{IO});
+    $| = 1;
+    print "";
+    $| = 0;
+    select($old_file);
   }
   elsif ($type eq ARRAY || $type eq SCALAR)
   {}
