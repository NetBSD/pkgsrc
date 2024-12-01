$NetBSD: patch-scripts_ZoneMinder_lib_ZoneMinder_Memory_Shared.pm,v 1.3 2024/12/01 13:49:48 gdt Exp $

Adjust for (more) modern perl.

Not submitted upstream because pkgsrc is woefully out of date.

--- scripts/ZoneMinder/lib/ZoneMinder/Memory/Shared.pm.orig	2023-02-23 21:44:01.000000000 +0000
+++ scripts/ZoneMinder/lib/ZoneMinder/Memory/Shared.pm
@@ -158,6 +158,9 @@ sub zmMemClean
                   .'\''
     ;
     Debug(2, 'Checking for shared memory with '.$command);
+    # \todo
+    # -    open( my $CMD, '<', "$command |" )
+    # +    open( my $CMD, '-|', "$command" )
     open( my $CMD, '<', $command.' |' )
         or Fatal( "Can't execute '$command': $!" );
     while( <$CMD> )
