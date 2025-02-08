$NetBSD: patch-gcc_ada_libgnarl_s-taprop____posix.adb,v 1.2 2025/02/08 14:05:03 wiz Exp $

When using SCHED_OTHER, the minimum and maximum in NetBSD is -1.
In most other OSs it is 0. Change the behaviour to try to set the
params using the default priority, if that fails, use 0, otherwise
use -1. If none are valid, the tasking system will fail if assertions
are on.

--- gcc/ada/libgnarl/s-taprop__posix.adb.orig	2024-05-21 10:47:37.000000000 +0300
+++ gcc/ada/libgnarl/s-taprop__posix.adb
@@ -635,6 +635,16 @@
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
