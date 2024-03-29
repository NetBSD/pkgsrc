$NetBSD: patch-extensions_exiv2__tools_exiv2-utils.cpp,v 1.2 2023/07/19 06:58:04 wiz Exp $

Fix build with exiv2 0.28.
https://gitlab.gnome.org/GNOME/gthumb/-/commit/3376550ae109286de09ce5f89e05060eb80230a7

--- extensions/exiv2_tools/exiv2-utils.cpp.orig	2022-04-03 18:38:59.000000000 +0000
+++ extensions/exiv2_tools/exiv2-utils.cpp
@@ -740,7 +740,11 @@ get_exif_default_category (const Exiv2::
 
 
 static void
+#if EXIV2_TEST_VERSION(0,28,0)
+exiv2_read_metadata (Exiv2::Image::UniquePtr  image,
+#else
 exiv2_read_metadata (Exiv2::Image::AutoPtr  image,
+#endif
 		     GFileInfo             *info,
 		     gboolean               update_general_attributes)
 {
@@ -875,7 +879,11 @@ exiv2_read_metadata_from_file (GFile    
 			return FALSE;
 		}
 
+#if EXIV2_TEST_VERSION(0,28,0)
+		Exiv2::Image::UniquePtr image = Exiv2::ImageFactory::open(path);
+#else
 		Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(path);
+#endif
 		g_free (path);
 
 		if (image.get() == 0) {
@@ -885,9 +893,17 @@ exiv2_read_metadata_from_file (GFile    
 		}
 		// Set the log level to only show errors (and suppress warnings, informational and debug messages)
 		Exiv2::LogMsg::setLevel(Exiv2::LogMsg::error);
+#if EXIV2_TEST_VERSION(0,28,0)
+		exiv2_read_metadata (std::move(image), info, update_general_attributes);
+#else
 		exiv2_read_metadata (image, info, update_general_attributes);
+#endif
 	}
+#if EXIV2_TEST_VERSION(0,28,0)
+	catch (Exiv2::Error& e) {
+#else
 	catch (Exiv2::AnyError& e) {
+#endif
 		if (error != NULL)
 			*error = g_error_new_literal (G_IO_ERROR, G_IO_ERROR_FAILED, e.what());
 		return FALSE;
@@ -906,7 +922,11 @@ exiv2_read_metadata_from_buffer (void   
 				 GError    **error)
 {
 	try {
+#if EXIV2_TEST_VERSION(0,28,0)
+		Exiv2::Image::UniquePtr image = Exiv2::ImageFactory::open ((Exiv2::byte*) buffer, buffer_size);
+#else
 		Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open ((Exiv2::byte*) buffer, buffer_size);
+#endif
 
 		if (image.get() == 0) {
 			if (error != NULL)
@@ -914,9 +934,17 @@ exiv2_read_metadata_from_buffer (void   
 			return FALSE;
 		}
 
+#if EXIV2_TEST_VERSION(0,28,0)
+		exiv2_read_metadata (std::move(image), info, update_general_attributes);
+#else
 		exiv2_read_metadata (image, info, update_general_attributes);
+#endif
 	}
+#if EXIV2_TEST_VERSION(0,28,0)
+	catch (Exiv2::Error& e) {
+#else
 	catch (Exiv2::AnyError& e) {
+#endif
 		if (error != NULL)
 			*error = g_error_new_literal (G_IO_ERROR, G_IO_ERROR_FAILED, e.what());
 		return FALSE;
@@ -965,7 +993,11 @@ exiv2_read_sidecar (GFile     *file,
 		g_free (path);
 
 		std::string xmpPacket;
+#if EXIV2_TEST_VERSION(0,28,0)
+		xmpPacket.assign(reinterpret_cast<char*>(buf.data()), buf.size());
+#else
 		xmpPacket.assign(reinterpret_cast<char*>(buf.pData_), buf.size_);
+#endif
 		Exiv2::XmpData xmpData;
 
 		if (0 != Exiv2::XmpParser::decode(xmpData, xmpPacket))
@@ -1011,7 +1043,11 @@ exiv2_read_sidecar (GFile     *file,
 
 		set_attributes_from_tagsets (info, update_general_attributes);
 	}
+#if EXIV2_TEST_VERSION(0,28,0)
+	catch (Exiv2::Error& e) {
+#else
 	catch (Exiv2::AnyError& e) {
+#endif
 		std::cerr << "Caught Exiv2 exception '" << e << "'\n";
 		return FALSE;
 	}
@@ -1111,7 +1147,11 @@ dump_exif_data (Exiv2::ExifData &exifDat
 
 
 static Exiv2::DataBuf
+#if EXIV2_TEST_VERSION(0,28,0)
+exiv2_write_metadata_private (Exiv2::Image::UniquePtr  image,
+#else
 exiv2_write_metadata_private (Exiv2::Image::AutoPtr  image,
+#endif
 			      GFileInfo             *info,
 			      GthImage              *image_data)
 {
@@ -1148,13 +1188,21 @@ exiv2_write_metadata_private (Exiv2::Ima
 			const char *value_type = gth_main_get_metadata_type (metadatum, attributes[i]);
 
 			if ((raw_value != NULL) && (strcmp (raw_value, "") != 0) && (value_type != NULL)) {
+#if EXIV2_TEST_VERSION(0,28,0)
+				Exiv2::Value::UniquePtr value = Exiv2::Value::create (Exiv2::TypeInfo::typeId (value_type));
+#else
 				Exiv2::Value::AutoPtr value = Exiv2::Value::create (Exiv2::TypeInfo::typeId (value_type));
+#endif
 				value->read (raw_value);
 				Exiv2::ExifKey exif_key(key);
 				ed.add (exif_key, value.get());
 			}
 		}
+#if EXIV2_TEST_VERSION(0,28,0)
+		catch (Exiv2::Error& e) {
+#else
 		catch (Exiv2::AnyError& e) {
+#endif
 			/* we don't care about invalid key errors */
 			g_warning ("%s", e.what());
 		}
@@ -1270,7 +1318,11 @@ exiv2_write_metadata_private (Exiv2::Ima
 			value_type = gth_main_get_metadata_type (metadatum, attributes[i]);
 			if (value_type != NULL) {
 				/* See the exif data code above for an explanation. */
+#if EXIV2_TEST_VERSION(0,28,0)
+				Exiv2::Value::UniquePtr value = Exiv2::Value::create (Exiv2::TypeInfo::typeId (value_type));
+#else
 				Exiv2::Value::AutoPtr value = Exiv2::Value::create (Exiv2::TypeInfo::typeId (value_type));
+#endif
 				Exiv2::IptcKey iptc_key(key);
 
 				const char *raw_value;
@@ -1296,7 +1348,11 @@ exiv2_write_metadata_private (Exiv2::Ima
 				}
 			}
 		}
+#if EXIV2_TEST_VERSION(0,28,0)
+		catch (Exiv2::Error& e) {
+#else
 		catch (Exiv2::AnyError& e) {
+#endif
 			/* we don't care about invalid key errors */
 			g_warning ("%s", e.what());
 		}
@@ -1320,7 +1376,11 @@ exiv2_write_metadata_private (Exiv2::Ima
 			value_type = gth_main_get_metadata_type (metadatum, attributes[i]);
 			if (value_type != NULL) {
 				/* See the exif data code above for an explanation. */
+#if EXIV2_TEST_VERSION(0,28,0)
+				Exiv2::Value::UniquePtr value = Exiv2::Value::create (Exiv2::TypeInfo::typeId (value_type));
+#else
 				Exiv2::Value::AutoPtr value = Exiv2::Value::create (Exiv2::TypeInfo::typeId (value_type));
+#endif
 				Exiv2::XmpKey xmp_key(key);
 
 				const char *raw_value;
@@ -1346,7 +1406,11 @@ exiv2_write_metadata_private (Exiv2::Ima
 				}
 			}
 		}
+#if EXIV2_TEST_VERSION(0,28,0)
+		catch (Exiv2::Error& e) {
+#else
 		catch (Exiv2::AnyError& e) {
+#endif
 			/* we don't care about invalid key errors */
 			g_warning ("%s", e.what());
 		}
@@ -1362,7 +1426,11 @@ exiv2_write_metadata_private (Exiv2::Ima
 		image->setXmpData(xd);
 		image->writeMetadata();
 	}
+#if EXIV2_TEST_VERSION(0,28,0)
+	catch (Exiv2::Error& e) {
+#else
 	catch (Exiv2::AnyError& e) {
+#endif
 		g_warning ("%s", e.what());
 	}
 
@@ -1389,16 +1457,33 @@ exiv2_write_metadata (GthImageSaveData *
 {
 	if (exiv2_supports_writes (data->mime_type) && (data->file_data != NULL)) {
 		try {
+#if EXIV2_TEST_VERSION(0,28,0)
+			Exiv2::Image::UniquePtr image = Exiv2::ImageFactory::open ((Exiv2::byte*) data->buffer, data->buffer_size);
+#else
 			Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open ((Exiv2::byte*) data->buffer, data->buffer_size);
+#endif
 			g_assert (image.get() != 0);
 
+#if EXIV2_TEST_VERSION(0,28,0)
+			Exiv2::DataBuf buf = exiv2_write_metadata_private (std::move(image), data->file_data->info, data->image);
+#else
 			Exiv2::DataBuf buf = exiv2_write_metadata_private (image, data->file_data->info, data->image);
+#endif
 
 			g_free (data->buffer);
+#if EXIV2_TEST_VERSION(0,28,0)
+			data->buffer = g_memdup (buf.data(), buf.size());
+			data->buffer_size = buf.size();
+#else
 			data->buffer = g_memdup (buf.pData_, buf.size_);
 			data->buffer_size = buf.size_;
+#endif
 		}
+#if EXIV2_TEST_VERSION(0,28,0)
+		catch (Exiv2::Error& e) {
+#else
 		catch (Exiv2::AnyError& e) {
+#endif
 			if (data->error != NULL)
 				*data->error = g_error_new_literal (G_IO_ERROR, G_IO_ERROR_FAILED, e.what());
 			g_warning ("%s\n", e.what());
@@ -1419,16 +1504,33 @@ exiv2_write_metadata_to_buffer (void    
 				GError    **error)
 {
 	try {
+#if EXIV2_TEST_VERSION(0,28,0)
+		Exiv2::Image::UniquePtr image = Exiv2::ImageFactory::open ((Exiv2::byte*) *buffer, *buffer_size);
+#else
 		Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open ((Exiv2::byte*) *buffer, *buffer_size);
+#endif
 		g_assert (image.get() != 0);
 
+#if EXIV2_TEST_VERSION(0,28,0)
+		Exiv2::DataBuf buf = exiv2_write_metadata_private (std::move(image), info, image_data);
+#else
 		Exiv2::DataBuf buf = exiv2_write_metadata_private (image, info, image_data);
+#endif
 
 		g_free (*buffer);
+#if EXIV2_TEST_VERSION(0,28,0)
+		*buffer = g_memdup (buf.data(), buf.size());
+		*buffer_size = buf.size();
+#else
 		*buffer = g_memdup (buf.pData_, buf.size_);
 		*buffer_size = buf.size_;
+#endif
 	}
+#if EXIV2_TEST_VERSION(0,28,0)
+	catch (Exiv2::Error& e) {
+#else
 	catch (Exiv2::AnyError& e) {
+#endif
 		if (error != NULL)
 			*error = g_error_new_literal (G_IO_ERROR, G_IO_ERROR_FAILED, e.what());
 		return FALSE;
@@ -1445,7 +1547,11 @@ exiv2_clear_metadata (void   **buffer,
 		      GError **error)
 {
 	try {
+#if EXIV2_TEST_VERSION(0,28,0)
+		Exiv2::Image::UniquePtr image = Exiv2::ImageFactory::open ((Exiv2::byte*) *buffer, *buffer_size);
+#else
 		Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open ((Exiv2::byte*) *buffer, *buffer_size);
+#endif
 
 		if (image.get() == 0) {
 			if (error != NULL)
@@ -1457,7 +1563,11 @@ exiv2_clear_metadata (void   **buffer,
 			image->clearMetadata();
 			image->writeMetadata();
 		}
+#if EXIV2_TEST_VERSION(0,28,0)
+		catch (Exiv2::Error& e) {
+#else
 		catch (Exiv2::AnyError& e) {
+#endif
 			g_warning ("%s", e.what());
 		}
 
@@ -1466,10 +1576,19 @@ exiv2_clear_metadata (void   **buffer,
 		Exiv2::DataBuf buf = io.read(io.size());
 
 		g_free (*buffer);
+#if EXIV2_TEST_VERSION(0,28,0)
+		*buffer = g_memdup (buf.data(), buf.size());
+		*buffer_size = buf.size();
+#else
 		*buffer = g_memdup (buf.pData_, buf.size_);
 		*buffer_size = buf.size_;
+#endif
 	}
+#if EXIV2_TEST_VERSION(0,28,0)
+	catch (Exiv2::Error& e) {
+#else
 	catch (Exiv2::AnyError& e) {
+#endif
 		if (error != NULL)
 			*error = g_error_new_literal (G_IO_ERROR, G_IO_ERROR_FAILED, e.what());
 		return FALSE;
@@ -1502,26 +1621,44 @@ exiv2_generate_thumbnail (const char *ur
 		if (path == NULL)
 			return NULL;
 
+#if EXIV2_TEST_VERSION(0,28,0)
+		Exiv2::Image::UniquePtr image = Exiv2::ImageFactory::open (path);
+#else
 		Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open (path);
+#endif
 		image->readMetadata ();
 		Exiv2::ExifThumbC exifThumb (image->exifData ());
 		Exiv2::DataBuf thumb = exifThumb.copy ();
 
 		g_free (path);
 
+#if EXIV2_TEST_VERSION(0,28,0)
+		if (thumb.data() == NULL)
+#else
 		if (thumb.pData_ == NULL)
+#endif
 			return NULL;
 
 		Exiv2::ExifData &ed = image->exifData();
 
+#if EXIV2_TEST_VERSION(0,28,0)
+		long orientation = (ed["Exif.Image.Orientation"].count() > 0) ? ed["Exif.Image.Orientation"].toUint32() : 1;
+		long image_width = (ed["Exif.Photo.PixelXDimension"].count() > 0) ? ed["Exif.Photo.PixelXDimension"].toUint32() : -1;
+		long image_height = (ed["Exif.Photo.PixelYDimension"].count() > 0) ? ed["Exif.Photo.PixelYDimension"].toUint32() : -1;
+#else
 		long orientation = (ed["Exif.Image.Orientation"].count() > 0) ? ed["Exif.Image.Orientation"].toLong() : 1;
 		long image_width = (ed["Exif.Photo.PixelXDimension"].count() > 0) ? ed["Exif.Photo.PixelXDimension"].toLong() : -1;
 		long image_height = (ed["Exif.Photo.PixelYDimension"].count() > 0) ? ed["Exif.Photo.PixelYDimension"].toLong() : -1;
+#endif
 
 		if ((orientation != 1) || (image_width <= 0) || (image_height <= 0))
 			return NULL;
 
+#if EXIV2_TEST_VERSION(0,28,0)
+		GInputStream *stream = g_memory_input_stream_new_from_data (thumb.data(), thumb.size(), NULL);
+#else
 		GInputStream *stream = g_memory_input_stream_new_from_data (thumb.pData_, thumb.size_, NULL);
+#endif
 		pixbuf = gdk_pixbuf_new_from_stream (stream, NULL, NULL);
 		g_object_unref (stream);
 
@@ -1575,7 +1712,11 @@ exiv2_generate_thumbnail (const char *ur
 		gdk_pixbuf_set_option (pixbuf, "orientation", orientation_s);
 		g_free (orientation_s);
 	}
+#if EXIV2_TEST_VERSION(0,28,0)
+	catch (Exiv2::Error& e) {
+#else
 	catch (Exiv2::AnyError& e) {
+#endif
 	}
 
 	return pixbuf;
