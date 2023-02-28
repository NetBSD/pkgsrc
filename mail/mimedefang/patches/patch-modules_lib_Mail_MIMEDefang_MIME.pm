$NetBSD: patch-modules_lib_Mail_MIMEDefang_MIME.pm,v 1.1 2023/02/28 20:23:13 bouyer Exp $

Fix https://github.com/The-McGrail-Foundation/MIMEDefang/issues/54
using https://github.com/The-McGrail-Foundation/MIMEDefang/commit/456aeb107d5bb8fd56cc440cb10adccc65bb55d2
Reported as issue #74

--- ./modules/lib/Mail/MIMEDefang/MIME.pm.orig	2023-02-28 20:47:36.956901101 +0100
+++ ./modules/lib/Mail/MIMEDefang/MIME.pm	2023-02-28 20:47:40.716138964 +0100
@@ -97,6 +97,7 @@
 	my $guess = $entity->head->recommended_filename();
 
 	if( defined $guess ) {
+		$guess =~ tr/\x00-\x7F/#/c;
 		return scalar( decode_mimewords( $guess ) );
 	}
 
