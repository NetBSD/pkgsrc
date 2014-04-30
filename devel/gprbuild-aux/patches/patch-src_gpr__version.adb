$NetBSD: patch-src_gpr__version.adb,v 1.1 2014/04/30 16:28:09 marino Exp $

Always use the FSF version (Not sure why Build_Type is not modified instead)

--- src/gpr_version.adb.orig	2013-04-16 14:36:02.000000000 +0000
+++ src/gpr_version.adb
@@ -65,14 +65,7 @@ package body GPR_Version is
          end if;
       end loop Last_Loop;
 
-      case Build_Type is
-         when Gnatpro =>
-            return "Pro " & Gpr_Version & " " & Date & Host;
-         when GPL =>
-            return "GPL " & Gpr_Version & " " & Date & Host;
-         when FSF =>
-            return Gpr_Version & " " & Date & Host;
-      end case;
+      return Gpr_Version & " " & Date & Host;
    end Gpr_Version_String;
 
 end GPR_Version;
