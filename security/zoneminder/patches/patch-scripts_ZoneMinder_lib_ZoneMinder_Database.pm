$NetBSD: patch-scripts_ZoneMinder_lib_ZoneMinder_Database.pm,v 1.1 2026/01/04 23:29:54 gdt Exp $

See ../files/upstream-PR-3914.

--- scripts/ZoneMinder/lib/ZoneMinder/Database.pm.orig	2025-12-07 16:18:50.000000000 +0000
+++ scripts/ZoneMinder/lib/ZoneMinder/Database.pm
@@ -103,11 +103,11 @@ sub zmDbConnect {
 
     eval {
       $dbh = DBI->connect(
-        'DBI:mysql:database='.$ZoneMinder::Config::Config{ZM_DB_NAME}
+        'DBI:'.$ZoneMinder::Config::Config{ZM_DB_TYPE}.':database='.$ZoneMinder::Config::Config{ZM_DB_NAME}
         .$socket . $sslOptions . ($options?join(';', '', map { $_.'='.$$options{$_} } keys %{$options} ) : '')
         , $ZoneMinder::Config::Config{ZM_DB_USER}
         , $ZoneMinder::Config::Config{ZM_DB_PASS}
-        , { mysql_enable_utf8mb4 => 1, }
+        , { ($ZoneMinder::Config::Config{ZM_DB_TYPE} eq 'mysql' ? (mysql_enable_utf8mb4 => 1) : ()) }
         );
     };
     if ( !$dbh or $@ ) {
