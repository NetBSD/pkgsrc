$NetBSD: patch-Source_FreeImage_PluginXPM.cpp,v 1.1 2017/02/20 08:00:42 snj Exp $

Fix CVE-2016-5684.

http://freeimage.cvs.sourceforge.net/viewvc/freeimage/FreeImage/Source/FreeImage/PluginXPM.cpp?r1=1.17&r2=1.18

and

http://freeimage.cvs.sourceforge.net/viewvc/freeimage/FreeImage/Source/FreeImage/PluginXPM.cpp?r1=1.18&r2=1.19

--- Source/FreeImage/PluginXPM.cpp.orig	2015-03-02 02:07:08.000000000 -0800
+++ Source/FreeImage/PluginXPM.cpp	2017-02-19 11:37:34.000000000 -0800
@@ -181,6 +181,11 @@ Load(FreeImageIO *io, fi_handle handle, 
 		}
 		free(str);
 
+		// check info string
+		if((width <= 0) || (height <= 0) || (colors <= 0) || (cpp <= 0)) {
+			throw "Improperly formed info string";
+		}
+
         if (colors > 256) {
 			dib = FreeImage_AllocateHeader(header_only, width, height, 24, FI_RGBA_RED_MASK, FI_RGBA_GREEN_MASK, FI_RGBA_BLUE_MASK);
 		} else {
@@ -193,7 +198,7 @@ Load(FreeImageIO *io, fi_handle handle, 
 			FILE_RGBA rgba;
 
 			str = ReadString(io, handle);
-			if(!str)
+			if(!str || (strlen(str) < (size_t)cpp))
 				throw "Error reading color strings";
 
 			std::string chrs(str,cpp); //create a string for the color chars using the first cpp chars
