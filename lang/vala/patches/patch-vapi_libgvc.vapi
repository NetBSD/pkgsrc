$NetBSD: patch-vapi_libgvc.vapi,v 1.1 2026/03/15 19:04:26 wiz Exp $

graphviz 13 compatibility.
https://gitlab.gnome.org/GNOME/vala/-/issues/1621

--- vapi/libgvc.vapi.orig	2026-03-15 19:01:35.978651710 +0000
+++ vapi/libgvc.vapi
@@ -91,7 +91,7 @@ namespace Gvc {
 		public int render_jobs (Graph graph);
 
 		[CCode (cname = "gvRenderData")]
-		public int render_data (Graph graph, [CCode (type = "char*")] string file_type, [CCode (array_length_type = "unsigned int", type = "char**")] out uint8[] output_data);
+		public int render_data (Graph graph, [CCode (type = "char*")] string file_type, [CCode (array_length_type = "size_t", type = "char**")] out uint8[] output_data);
 	}
 
 	[Compact]
