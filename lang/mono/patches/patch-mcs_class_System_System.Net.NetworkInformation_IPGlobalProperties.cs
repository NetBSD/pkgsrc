$NetBSD: patch-mcs_class_System_System.Net.NetworkInformation_IPGlobalProperties.cs,v 1.1 2017/08/22 13:43:35 jperkin Exp $

Support getdomainname being in a library other than libc.

--- mcs/class/System/System.Net.NetworkInformation/IPGlobalProperties.cs.orig	2015-08-25 20:33:28.000000000 +0000
+++ mcs/class/System/System.Net.NetworkInformation/IPGlobalProperties.cs
@@ -96,7 +96,7 @@ namespace System.Net.NetworkInformation
 		[DllImport ("libc")]
 		static extern int gethostname ([MarshalAs (UnmanagedType.LPArray, SizeParamIndex = 1)] byte [] name, int len);
 
-		[DllImport ("libc")]
+		[DllImport ("@DOMAINLIB@")]
 		static extern int getdomainname ([MarshalAs (UnmanagedType.LPArray, SizeParamIndex = 1)] byte [] name, int len);
 
 		public override string DhcpScopeName {
