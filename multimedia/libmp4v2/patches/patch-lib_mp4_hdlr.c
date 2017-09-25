$NetBSD: patch-lib_mp4_hdlr.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/hdlr.c.orig	2017-09-25 14:53:18.531936562 +0000
+++ lib/mp4/hdlr.c
@@ -2,7 +2,7 @@
 
 
 
-int quicktime_hdlr_init(quicktime_hdlr_t *hdlr)
+void quicktime_hdlr_init(quicktime_hdlr_t *hdlr)
 {
 	hdlr->version = 0;
 	hdlr->flags = 0;
@@ -20,7 +20,7 @@ int quicktime_hdlr_init(quicktime_hdlr_t
 	strcpy(hdlr->component_name, "Linux Media Handler");
 }
 
-int quicktime_hdlr_init_video(quicktime_hdlr_t *hdlr)
+void quicktime_hdlr_init_video(quicktime_hdlr_t *hdlr)
 {
 	hdlr->component_subtype[0] = 'v';
 	hdlr->component_subtype[1] = 'i';
@@ -29,7 +29,7 @@ int quicktime_hdlr_init_video(quicktime_
 	strcpy(hdlr->component_name, "Linux Video Media Handler");
 }
 
-int quicktime_hdlr_init_audio(quicktime_hdlr_t *hdlr)
+void quicktime_hdlr_init_audio(quicktime_hdlr_t *hdlr)
 {
 	hdlr->component_subtype[0] = 's';
 	hdlr->component_subtype[1] = 'o';
@@ -38,7 +38,7 @@ int quicktime_hdlr_init_audio(quicktime_
 	strcpy(hdlr->component_name, "Linux Sound Media Handler");
 }
 
-int quicktime_hdlr_init_hint(quicktime_hdlr_t *hdlr)
+void quicktime_hdlr_init_hint(quicktime_hdlr_t *hdlr)
 {
 	hdlr->component_subtype[0] = 'h';
 	hdlr->component_subtype[1] = 'i';
@@ -47,7 +47,7 @@ int quicktime_hdlr_init_hint(quicktime_h
 	strcpy(hdlr->component_name, "Linux Hint Media Handler");
 }
 
-int quicktime_hdlr_init_data(quicktime_hdlr_t *hdlr)
+void quicktime_hdlr_init_data(quicktime_hdlr_t *hdlr)
 {
 	hdlr->component_type[0] = 'd';
 	hdlr->component_type[1] = 'h';
@@ -60,21 +60,21 @@ int quicktime_hdlr_init_data(quicktime_h
 	strcpy(hdlr->component_name, "Linux Alias Data Handler");
 }
 
-int quicktime_hdlr_delete(quicktime_hdlr_t *hdlr)
+void quicktime_hdlr_delete(quicktime_hdlr_t *hdlr)
 {
 }
 
-int quicktime_hdlr_dump(quicktime_hdlr_t *hdlr)
+void quicktime_hdlr_dump(quicktime_hdlr_t *hdlr)
 {
 	printf("   handler reference (hdlr)\n");
 	printf("    version %d\n", hdlr->version);
-	printf("    flags %d\n", hdlr->flags);
+	printf("    flags %ld\n", hdlr->flags);
 	printf("    component_type %c%c%c%c\n", hdlr->component_type[0], hdlr->component_type[1], hdlr->component_type[2], hdlr->component_type[3]);
 	printf("    component_subtype %c%c%c%c\n", hdlr->component_subtype[0], hdlr->component_subtype[1], hdlr->component_subtype[2], hdlr->component_subtype[3]);
 	printf("    component_name %s\n", hdlr->component_name);
 }
 
-int quicktime_read_hdlr(quicktime_t *file, quicktime_hdlr_t *hdlr)
+void quicktime_read_hdlr(quicktime_t *file, quicktime_hdlr_t *hdlr)
 {
 	hdlr->version = quicktime_read_char(file);
 	hdlr->flags = quicktime_read_int24(file);
@@ -90,7 +90,7 @@ int quicktime_read_hdlr(quicktime_t *fil
 	}
 }
 
-int quicktime_write_hdlr(quicktime_t *file, quicktime_hdlr_t *hdlr)
+void quicktime_write_hdlr(quicktime_t *file, quicktime_hdlr_t *hdlr)
 {
 	quicktime_atom_t atom;
 	quicktime_atom_write_header(file, &atom, "hdlr");
