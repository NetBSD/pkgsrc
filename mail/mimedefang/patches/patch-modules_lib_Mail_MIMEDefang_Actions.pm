$NetBSD: patch-modules_lib_Mail_MIMEDefang_Actions.pm,v 1.1 2023/03/03 11:19:19 bouyer Exp $
Patch from upstream (commit a6470d7) to fix issue with non-ascii filenames
(issue 74)

--- modules/lib/Mail/MIMEDefang/Actions.pm.orig	2023-03-02 15:01:50.625588453 +0100
+++ modules/lib/Mail/MIMEDefang/Actions.pm	2023-03-02 15:02:54.632130347 +0100
@@ -139,10 +139,17 @@
 
     my ($part);
 
+    my $charset = undef;
+    if (utf8::is_utf8($data)) {
+      utf8::encode($data);
+      $charset = 'utf-8';
+    }
+
     $part = MIME::Entity->build(Type => $type,
 				Top => 0,
 				'X-Mailer' => undef,
 				Encoding => $encoding,
+				Charset => $charset,
 				Data => ["$data"]);
     defined ($fname) && $part->head->mime_attr("Content-Type.name" => $fname);
     defined ($disposition) && $part->head->mime_attr("Content-Disposition" => $disposition);
