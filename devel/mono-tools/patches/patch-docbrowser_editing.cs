$NetBSD: patch-docbrowser_editing.cs,v 1.1 2015/05/23 06:57:15 kefren Exp $

Disable this function because Monodoc.Providers.EcmaUncompiledHelpSource is not available anymore

From https://build.opensuse.org/package/view_file/home:tpokorra:mono/mono-tools/docbrowser.patch?expand=1

--- docbrowser/editing.cs.orig	2015-05-22 17:18:35.000000000 +0300
+++ docbrowser/editing.cs	2015-05-22 17:19:17.000000000 +0300
@@ -131,21 +131,6 @@ namespace Monodoc {
 		
 		public static void RenderEditPreview (string url, RootTree tree, XmlNode new_node, XmlWriter w)
 		{
-			string [] uSplit = ParseEditUrl (url);
-		
-			if (uSplit[0].StartsWith("monodoc:///")) {
-				int prov = int.Parse (uSplit [0].Substring("monodoc:///".Length));
-				HelpSource hs = tree.GetHelpSourceFromId (prov);
-				hs.RenderPreviewDocs (new_node, w);
-			} else {
-				foreach (HelpSource hs in tree.HelpSources) {
-					if (hs is Monodoc.Providers.EcmaUncompiledHelpSource) {
-						// It doesn't matter which EcmaHelpSource is chosen.
-						hs.RenderPreviewDocs (new_node, w);
-						break;
-					}
-				}				
-			}
 		}
 		
 		public static string [] ParseEditUrl (string url)
