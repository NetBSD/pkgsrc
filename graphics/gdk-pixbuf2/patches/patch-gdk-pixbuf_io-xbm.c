$NetBSD: patch-gdk-pixbuf_io-xbm.c,v 1.1 2012/06/12 14:54:23 taca Exp $

Fix for http://secunia.com/advisories/49125/.

--- gdk-pixbuf/io-xbm.c.orig	2012-04-14 18:20:25.000000000 +0000
+++ gdk-pixbuf/io-xbm.c
@@ -149,7 +149,8 @@ read_bitmap_file_data (FILE    *fstream,
 		       guint   *height,
 		       guchar **data,
 		       int     *x_hot, 
-		       int     *y_hot)
+		       int     *y_hot,
+		       GError  **error)
 {
 	guchar *bits = NULL;		/* working variable */
 	char line[MAX_SIZE];		/* input line from file */
@@ -171,11 +172,18 @@ read_bitmap_file_data (FILE    *fstream,
 	}
 
 	/* error cleanup and return macro */
-#define	RETURN(code) { g_free (bits); return code; }
+#define	RETURN(code, message) { \
+            g_free (bits); \
+            g_set_error_literal (error, \
+            GDK_PIXBUF_ERROR, \
+            GDK_PIXBUF_ERROR_CORRUPT_IMAGE, \
+            message); \
+            return code; \
+        }
 
 	while (fgets (line, MAX_SIZE, fstream)) {
 		if (strlen (line) == MAX_SIZE-1)
-			RETURN (FALSE);
+			RETURN (FALSE, _("XBM file contain too long line"));
 		if (sscanf (line,"#define %s %d",name_and_type,&value) == 2) {
 			if (!(type = strrchr (name_and_type, '_')))
 				type = name_and_type;
@@ -185,12 +193,12 @@ read_bitmap_file_data (FILE    *fstream,
 
 			if (!strcmp ("width", type)) {
                                 if (value <= 0)
-                                        RETURN (FALSE);
+					RETURN (FALSE, _("Negative width in XBM file"));
 				ww = (unsigned int) value;
                         }
 			if (!strcmp ("height", type)) {
                                 if (value <= 0)
-                                        RETURN (FALSE);
+					RETURN (FALSE, _("Negative height in XBM file"));
 				hh = (unsigned int) value;
                         }
 			if (!strcmp ("hot", type)) {
@@ -227,7 +235,7 @@ read_bitmap_file_data (FILE    *fstream,
 			continue;
     
 		if (!ww || !hh)
-			RETURN (FALSE);
+			RETURN (FALSE, _("Width or height of XBM image is zero"));
 
 		if ((ww % 16) && ((ww % 16) < 9) && version10p)
 			padding = 1;
@@ -237,8 +245,9 @@ read_bitmap_file_data (FILE    *fstream,
 		bytes_per_line = (ww+7)/8 + padding;
 
 		size = bytes_per_line * hh;
-                if (size / bytes_per_line != hh) /* overflow */
-                        RETURN (FALSE);
+		if (size / bytes_per_line != hh) { /* overflow */
+			RETURN (FALSE, _("Dimensions of XBM image too large"));
+		}
 		bits = g_malloc (size);
 
 		if (version10p) {
@@ -247,7 +256,7 @@ read_bitmap_file_data (FILE    *fstream,
 
 			for (bytes = 0, ptr = bits; bytes < size; (bytes += 2)) {
 				if ((value = next_int (fstream)) < 0)
-					RETURN (FALSE);
+					RETURN (FALSE, _("Unexpected end of XBM file"));
 				*(ptr++) = value;
 				if (!padding || ((bytes+2) % bytes_per_line))
 					*(ptr++) = value >> 8;
@@ -258,7 +267,7 @@ read_bitmap_file_data (FILE    *fstream,
 
 			for (bytes = 0, ptr = bits; bytes < size; bytes++, ptr++) {
 				if ((value = next_int (fstream)) < 0) 
-					RETURN (FALSE);
+					RETURN (FALSE, _("Unexpected end of XBM file"));
 				*ptr=value;
 			}
 		}
@@ -266,7 +275,7 @@ read_bitmap_file_data (FILE    *fstream,
 	}
 
 	if (!bits)
-		RETURN (FALSE);
+		RETURN (FALSE, _("Insufficient memory to open XBM file"));
 
 	*data = bits;
 	*width = ww;
@@ -297,11 +306,7 @@ gdk_pixbuf__xbm_image_load_real (FILE   
 
 	GdkPixbuf *pixbuf;
 
-	if (!read_bitmap_file_data (f, &w, &h, &data, &x_hot, &y_hot)) {
-                g_set_error_literal (error,
-                                     GDK_PIXBUF_ERROR,
-                                     GDK_PIXBUF_ERROR_CORRUPT_IMAGE,
-                                     _("Invalid XBM file"));
+	if (!read_bitmap_file_data (f, &w, &h, &data, &x_hot, &y_hot, error)) {
 		return NULL;
 	}
 
