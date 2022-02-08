$NetBSD: patch-mcs_class_System_System_Platform.cs,v 1.1 2022/02/08 13:39:17 gavan Exp $

--- mcs/class/System/System/Platform.cs.orig	2021-02-22 15:50:13.000000000 +0000
+++ mcs/class/System/System/Platform.cs
@@ -53,6 +53,7 @@ namespace System {
 #else
 		static bool isFreeBSD;
 		static bool isOpenBSD;
+		static bool isNetBSD;
 
 		[DllImport ("libc")]
 		static extern int uname (IntPtr buf);
@@ -82,6 +83,9 @@ namespace System {
 				case "OpenBSD":
 					isOpenBSD = true;
 					break;
+				case "NetBSD":
+					isNetBSD = true;
+					break;
 				}
 			}
 			Marshal.FreeHGlobal (buf);
@@ -113,6 +117,14 @@ namespace System {
 			}
 		}
 
+		public static bool IsNetBSD {
+			get {
+				if (!checkedOS)
+					CheckOS();
+				return isNetBSD;
+			}
+		}
+
 		public static bool IsIBMi {
 			get {
 				if (!checkedOS)
