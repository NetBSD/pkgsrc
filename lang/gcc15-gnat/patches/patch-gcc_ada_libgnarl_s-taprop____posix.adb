$NetBSD: patch-gcc_ada_libgnarl_s-taprop____posix.adb,v 1.1 2025/07/17 05:00:17 dkazankov Exp $

When using SCHED_OTHER, the minimum and maximum in NetBSD is -1.
In most other OSs it is 0. Change the behaviour to try to set the
params using the default priority, if that fails, use 0, otherwise
use -1. If none are valid, the tasking system will fail if assertions
are on.

--- gcc/ada/libgnarl/s-taprop__posix.adb.orig	2025-04-25 08:18:00.000000000 +0000
+++ gcc/ada/libgnarl/s-taprop__posix.adb
@@ -616,6 +616,16 @@
       else
          Result := pthread_setschedparam
            (T.Common.LL.Thread, SCHED_OTHER, Param'Access);
+         if Result /= 0 then
+            Param.sched_priority := 0;
+            Result := pthread_setschedparam
+              (T.Common.LL.Thread, SCHED_OTHER, Param'Access);
+            if Result /= 0 then
+               Param.sched_priority := -1;
+               Result := pthread_setschedparam
+                 (T.Common.LL.Thread, SCHED_OTHER, Param'Access);
+            end if;
+         end if;
       end if;
 
       pragma Assert (Result = 0);
