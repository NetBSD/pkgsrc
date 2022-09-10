$NetBSD: patch-plug-ins_common_file-heif.c,v 1.1 2022/09/10 09:24:48 wiz Exp $

Fix build with heif 1.13.0
https://gitlab.gnome.org/GNOME/gimp/-/commit/a61299ddb184babca015a846c72bf3e1a57faf2a

--- plug-ins/common/file-heif.c.orig	2022-08-21 19:21:38.000000000 +0000
+++ plug-ins/common/file-heif.c
@@ -56,24 +56,24 @@ typedef enum _HeifpluginExportFormat
   HEIFPLUGIN_EXPORT_FORMAT_YUV420 = 3
 } HeifpluginExportFormat;
 
-typedef struct _Heif      Heif;
-typedef struct _HeifClass HeifClass;
+typedef struct _GimpHeif      GimpHeif;
+typedef struct _GimpHeifClass GimpHeifClass;
 
-struct _Heif
+struct _GimpHeif
 {
   GimpPlugIn      parent_instance;
 };
 
-struct _HeifClass
+struct _GimpHeifClass
 {
   GimpPlugInClass parent_class;
 };
 
 
-#define HEIF_TYPE  (heif_get_type ())
-#define HEIF (obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), HEIF_TYPE, Heif))
+#define GIMP_HEIF_TYPE  (gimp_heif_get_type ())
+#define GIMP_HEIF (obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GIMP_HEIF_TYPE, GimpHeif))
 
-GType                   heif_get_type         (void) G_GNUC_CONST;
+GType                   gimp_heif_get_type    (void) G_GNUC_CONST;
 
 static GList          * heif_init_procedures  (GimpPlugIn           *plug_in);
 static GimpProcedure  * heif_create_procedure (GimpPlugIn           *plug_in,
@@ -123,14 +123,14 @@ static gboolean         save_dialog     
                                                GimpImage            *image);
 
 
-G_DEFINE_TYPE (Heif, heif, GIMP_TYPE_PLUG_IN)
+G_DEFINE_TYPE (GimpHeif, gimp_heif, GIMP_TYPE_PLUG_IN)
 
-GIMP_MAIN (HEIF_TYPE)
+GIMP_MAIN (GIMP_HEIF_TYPE)
 DEFINE_STD_SET_I18N
 
 
 static void
-heif_class_init (HeifClass *klass)
+gimp_heif_class_init (GimpHeifClass *klass)
 {
   GimpPlugInClass *plug_in_class = GIMP_PLUG_IN_CLASS (klass);
 
@@ -140,7 +140,7 @@ heif_class_init (HeifClass *klass)
 }
 
 static void
-heif_init (Heif *heif)
+gimp_heif_init (GimpHeif *heif)
 {
 }
 
