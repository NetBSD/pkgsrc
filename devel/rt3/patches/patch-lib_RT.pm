$NetBSD: patch-lib_RT.pm,v 1.1 2011/10/25 19:38:10 spz Exp $

perl 5.14 qw() in for* fixes

--- lib/RT.pm.orig	2011-04-14 01:10:13.000000000 +0000
+++ lib/RT.pm
@@ -459,7 +459,7 @@ sub InitClasses {
     # in the session, as we deserialize it so we never call constructor
     # of the class, so the list of accessible fields is empty and we die
     # with "Method xxx is not implemented in RT::SomeClass"
-    $_->_BuildTableAttributes foreach qw(
+    $_->_BuildTableAttributes foreach ( qw(
         RT::Ticket
         RT::Transaction
         RT::Attachment
@@ -477,7 +477,7 @@ sub InitClasses {
         RT::ObjectCustomField
         RT::ObjectCustomFieldValue
         RT::Attribute
-    );
+    ) );
 
     if ( $args{'Heavy'} ) {
         # load scrips' modules
