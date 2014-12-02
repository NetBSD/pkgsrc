$NetBSD: patch-mcs_class_System.Web_System.Web.UI_Page.cs,v 1.1.2.2 2014/12/02 22:59:51 tron Exp $

patch 4 for CVE-2012-3543 from
https://github.com/mono/mono/commit/c3e088bf2fc22d66d0f17b74676de366f661c3eb

--- mcs/class/System.Web/System.Web.UI/Page.cs.orig	2011-11-15 17:22:42.000000000 +0000
+++ mcs/class/System.Web/System.Web.UI/Page.cs
@@ -1175,7 +1175,7 @@ public partial class Page : TemplateCont
 
 	void ProcessPostData (NameValueCollection data, bool second)
 	{
-		NameValueCollection requestValues = _requestValueCollection == null ? new NameValueCollection () : _requestValueCollection;
+		NameValueCollection requestValues = _requestValueCollection == null ? new NameValueCollection (SecureHashCodeProvider.DefaultInvariant, CaseInsensitiveComparer.DefaultInvariant) : _requestValueCollection;
 		
 		if (data != null && data.Count > 0) {
 			var used = new Dictionary <string, string> (StringComparer.Ordinal);
@@ -1210,7 +1210,7 @@ public partial class Page : TemplateCont
 
 				} else if (!second) {
 					if (secondPostData == null)
-						secondPostData = new NameValueCollection ();
+						secondPostData = new NameValueCollection (SecureHashCodeProvider.DefaultInvariant, CaseInsensitiveComparer.DefaultInvariant);
 					secondPostData.Add (id, data [id]);
 				}
 			}
