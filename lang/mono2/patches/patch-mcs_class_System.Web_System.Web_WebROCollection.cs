$NetBSD: patch-mcs_class_System.Web_System.Web_WebROCollection.cs,v 1.1.2.2 2014/12/02 22:59:51 tron Exp $

patch for CVE-2012-3543 from
https://github.com/mono/mono/commit/c3e088bf2fc22d66d0f17b74676de366f661c3eb
part 3

--- mcs/class/System.Web/System.Web/WebROCollection.cs.orig	2011-11-15 17:22:42.000000000 +0000
+++ mcs/class/System.Web/System.Web/WebROCollection.cs
@@ -5,6 +5,7 @@
 //   	Gonzalo Paniagua Javier (gonzalo@novell.com)
 //
 // (c) 2005-2009 Novell, Inc. (http://www.novell.com)
+// Copyright 2012 Xamarin, Inc (http://xamarin.com)
 //
 //
 // Permission is hereby granted, free of charge, to any person obtaining
@@ -26,8 +27,10 @@
 // OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 // WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 //
+using System.Collections;
 using System.Collections.Specialized;
 using System.Text;
+using System.Web.Util;
 
 namespace System.Web
 {
@@ -36,7 +39,7 @@ namespace System.Web
 		bool got_id;
 		int id;
 
-		public WebROCollection () : base (StringComparer.OrdinalIgnoreCase) { }
+		public WebROCollection () : base (SecureHashCodeProvider.DefaultInvariant, CaseInsensitiveComparer.DefaultInvariant) { }
 		public bool GotID {
 			get { return got_id; }
 		}
