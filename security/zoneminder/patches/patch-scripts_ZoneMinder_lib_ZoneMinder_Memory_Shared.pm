$NetBSD: patch-scripts_ZoneMinder_lib_ZoneMinder_Memory_Shared.pm,v 1.4 2026/07/30 12:36:00 gdt Exp $

Add a comment leftover from a previous debugging attempt.
This entire patchfile is a deletion candidate.

Not submitted upstream because pkgsrc does not have a coherent story
about this proposed patch.

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
