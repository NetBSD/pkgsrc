$NetBSD: patch-pstoedit__3.21_src_drvtk.cpp,v 1.1 2011/11/25 21:57:36 joerg Exp $

--- pstoedit_3.21/src/drvtk.cpp.orig	2000-10-03 20:00:50.000000000 +0000
+++ pstoedit_3.21/src/drvtk.cpp
@@ -26,17 +26,21 @@
 */
 
 #include "drvtk.h"
-#include <iostream.h>
+#include <iostream>
 #include <stdio.h>
 #include <string.h>
 
 // for sin and cos
 #include <math.h>
 
+#include "version.h"
+
 
 static const char * tagNames = "";
 static int swapHW = 0;
 static int noImPress = 0;
+static int doImages = 0;
+static char* PNGoutFullFileName = new char [2048];
 
 static const char * colorstring(float r, float g, float b)
 {
@@ -70,10 +74,12 @@ void drvTK::outputEscapedText(const char
 drvTK::derivedConstructor(drvTK):
 	constructBase,
 	buffer(tempFile.asOutput()),
-	objectId            (1)
+	objectId            (1),
+	imgcount(0)
 {
 //	const RSString & l_pagesize = getPageSize();
 
+	cerr << "pstoedit: Backend for Tk (ImPress 1.1b9)\n";
     // set tk specific values
     scale = 1.0;		/* tk default internal scale factor */
 
@@ -92,6 +98,8 @@ drvTK::derivedConstructor(drvTK):
 			swapHW = 1;
 		} else if (!strcmp(d_argv[i], "-I")) {
 			noImPress = 1;
+		} else if (!strcmp(d_argv[i], "-i")) {
+			doImages = 1;
 		}
     }  
 	strcpy(pwidth, "8.5i");
@@ -460,6 +468,9 @@ void drvTK::canvasCreate()
     << "set Global(Circulate) 1" << endl
     << "set Global(SlideScale) 0" << endl;
 	}
+	if (doImages) {
+		outf << "package require Img" << endl;
+	}
 }
 
 drvTK::~drvTK() 
@@ -478,6 +489,9 @@ void drvTK::print_coords()
 	float pc_x;
 	float pc_y;	
 	for (unsigned int n = 0; n < numberOfElementsInPath(); n++) {
+		if (pathElement(n).getType() == closepath) {
+			break;
+		}
 		const Point & p = pathElement(n).getPoint(0);
 		pc_x = (p.x_ + x_offset) * scale;
 		pc_y = (currentDeviceHeight - p.y_ + y_offset) * scale;
@@ -591,12 +605,10 @@ void drvTK::show_path()
 		} else {
 			buffer << " -fill \"\"";
 		}
-		buffer << " -outline \""
-	 	<< colorstring(currentR(),currentG(),currentB())
-	 	<< "\""
+		// Outline is always nothing in postscript polygons
+		buffer << " -outline \"\""
 	 	<< " -width "
 	 	<< (currentLineWidth()?currentLineWidth():1)
-		<< "p"
 	 	<< " -tags \""
 	 	<< tagNames
 	 	<< "\" ]"
@@ -608,12 +620,10 @@ void drvTK::show_path()
 			buffer << " -fill \""
 			<< colorstring(currentR(),currentG(),currentB())
 			<< "\"";
-			buffer << " -outline \""
-	 		<< colorstring(currentR(),currentG(),currentB())
-	 		<< "\""
+			// Outline is always nothing in postscript polygons
+			buffer << " -outline \"\""
 	 		<< " -width "
 	 		<< (currentLineWidth()?currentLineWidth():1)
-			<< "p"
 	 		<< " -tags \""
 	 		<< tagNames
 	 		<< "\" ]"
@@ -626,7 +636,6 @@ void drvTK::show_path()
 			<< "\""
 			<< " -width "
 	 		<< (currentLineWidth()?currentLineWidth():1)
-			<< "p"
 			<< " -tags \""
 			<< tagNames
 			<< "\" ]"
@@ -650,9 +659,38 @@ void drvTK::show_rectangle(const float l
 	show_path();
 }
 
+void drvTK::show_image(const Image & imageinfo)
+{
+	if (doImages) {
+		Point lowerleft, upperright;
+		imageinfo.getBoundingBox(lowerleft, upperright);
+
+    	sprintf(PNGoutFullFileName, "%s%s%02d.png", outDirName, outBaseName, imgcount++);
+
+		char * title = new char [strlen(inFileName.value())+100];
+		sprintf(title,"raster image number %d from input file %s",imgcount,inFileName.value());
+		char generator[100];
+		sprintf(generator,"pstoedit version: %s",version);
+		imageinfo.writePNGImage(PNGoutFullFileName,inFileName.value(),title,generator);
+
+		delete[] title;
+	
+		buffer << "image create photo {" << PNGoutFullFileName << "} -file {" << PNGoutFullFileName << "}" << endl;
+		buffer << "set i [$Global(CurrentCanvas) create image "
+			<< ((lowerleft.x_ + x_offset) * scale) << " "
+			<< ((currentDeviceHeight - lowerleft.y_ + y_offset) * scale)
+			<< " -image {" << PNGoutFullFileName << "}"
+			<< " -anchor sw"
+			<< " -tags \""
+			<< tagNames
+			<< "\" ]"
+			<< endl;
+	}
+}
+
 static DriverDescriptionT<drvTK> D_tk(
 			"tk","tk and/or tk applet source code","tk",
-		false, // backend supports subpathes
+		true, // backend supports subpathes
 		   // if subpathes are supported, the backend must deal with
 		   // sequences of the following form
 		   // moveto (start of subpath)
@@ -669,7 +707,7 @@ static DriverDescriptionT<drvTK> D_tk(
 		false, // backend supports curves
 		false, // backend supports elements which are filled and have edges
 		true, // backend supports text
-		false, // backend supports Images
+		true, // backend supports Images
 		DriverDescription::normalopen,	
 		true); // backend support multiple pages
  
