$NetBSD: patch-kipi-plugins_imageviewer_viewerwidget.cpp,v 1.1 2012/10/26 20:38:24 joerg Exp $

--- kipi-plugins/imageviewer/viewerwidget.cpp.orig	2008-12-13 11:20:05.000000000 +0000
+++ kipi-plugins/imageviewer/viewerwidget.cpp
@@ -59,16 +59,16 @@ ViewerWidget::ViewerWidget(KIPI::Interfa
 		file_idx=0; //index of picture to be displayed
 
 		if ( selection.images().count()==0 ) {
-			kdDebug(51000) << "no image selected, load entire album" << endl;
+			kdDebug(51000) << "no image selected, load entire album" << ::endl;
 			myfiles = album.images();
 		} 
 		else if ( selection.images().count()==1 ) {
-			kdDebug(51000) << "one image selected, load entire album and start with selected image" << endl;
+			kdDebug(51000) << "one image selected, load entire album and start with selected image" << ::endl;
 			selectedImage = selection.images().first().path();
 			myfiles = album.images();
 		} 
 		else if ( selection.images().count()>1 ) {
-			kdDebug(51000) << "load " << selection.images().count() << " selected images" << endl;
+			kdDebug(51000) << "load " << selection.images().count() << " selected images" << ::endl;
 			myfiles = selection.images();
 		}
 
@@ -79,7 +79,7 @@ ViewerWidget::ViewerWidget(KIPI::Interfa
 			// in case one image was selected and the entire album was loaded
 			QString s = (*it).path();
 			if ( s==selectedImage ) {
-				kdDebug(51000) << "selected img  " << selectedImage << " has idx=" << foundNumber << endl;
+				kdDebug(51000) << "selected img  " << selectedImage << " has idx=" << foundNumber << ::endl;
 				file_idx=foundNumber;
 			}
 			
@@ -90,12 +90,12 @@ ViewerWidget::ViewerWidget(KIPI::Interfa
 			if ( isImage ) {
 				files.append(s);
 				foundNumber++;  //counter for searching the start image in case one image is selected
-				kdDebug(51000) << s << " type=" << type->name() << endl;
+				kdDebug(51000) << s << " type=" << type->name() << ::endl;
 			}
 		}
 		
 		firstImage=true;
-		kdDebug(51000) << files.count() << "images loaded" << endl;
+		kdDebug(51000) << files.count() << "images loaded" << ::endl;
 		
 		// initialize cache
 		for(int i=0;i<CACHESIZE;i++) {
@@ -220,7 +220,7 @@ void ViewerWidget::resizeGL(int w, int h
  */
 void ViewerWidget::drawImage(Texture * texture)
 {
-// 	cout << "enter drawImage: target=" << texture->texnr() << " dim=" << texture->height() << " " << texture->width() << endl;	
+// 	cout << "enter drawImage: target=" << texture->texnr() << " dim=" << texture->height() << " " << texture->width() << ::endl;	
 	glBindTexture(GL_TEXTURE_RECTANGLE_NV, texture->texnr());
 	glBegin(GL_QUADS); 
 		glTexCoord2f(0, 0);
@@ -418,13 +418,13 @@ Texture * ViewerWidget::loadImage(int fi
 
 	if (cache[imod].file_index==file_index){ 
 		//image is already cached	
-		kdDebug(51000) << "image " << file_index << " is already in cache@" << imod << endl;
+		kdDebug(51000) << "image " << file_index << " is already in cache@" << imod << ::endl;
 		return cache[imod].texture;
 
 	} else {
 		// image is net yet loaded
 		QString f = files[file_index];
-		kdDebug(51000) << "loading image " << f << "(idx=" << file_index << ") to cache@" << imod << endl;
+		kdDebug(51000) << "loading image " << f << "(idx=" << file_index << ") to cache@" << imod << ::endl;
 		cache[imod].file_index=file_index;
 
 		// handle non-loadable images
