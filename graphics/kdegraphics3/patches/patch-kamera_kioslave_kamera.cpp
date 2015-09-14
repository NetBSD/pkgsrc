$NetBSD: patch-kamera_kioslave_kamera.cpp,v 1.1 2015/09/14 13:31:54 joerg Exp $

--- kamera/kioslave/kamera.cpp.orig	2015-09-13 16:49:10.000000000 +0000
+++ kamera/kioslave/kamera.cpp
@@ -55,10 +55,9 @@ extern "C"
 {
 	KDE_EXPORT int kdemain(int argc, char **argv);
 
-	static void frontendCameraStatus(GPContext *context, const char *format, va_list args, void *data);
+	static void frontendCameraStatus(GPContext *context, const char *text, void *data);
 	static unsigned int frontendProgressStart(
-		GPContext *context, float totalsize, const char *format,
-		va_list args, void *data
+		GPContext *context, float totalsize, const char *text, void *data
 	);
 	static void frontendProgressUpdate(
 		GPContext *context, unsigned int id, float current, void *data
@@ -857,10 +856,7 @@ void KameraProtocol::translateFileToUDS(
 	udsEntry.append(atom);
 
 	atom.m_uds = UDS_NAME;
-	if (info.file.fields & GP_FILE_INFO_NAME)
-		atom.m_str = QString::fromLocal8Bit(info.file.name);
-	else
-		atom.m_str = name;
+	atom.m_str = name;
 	udsEntry.append(atom);
 
 	if (info.file.fields & GP_FILE_INFO_SIZE) {
@@ -986,81 +982,25 @@ void frontendProgressUpdate(
 }
 
 unsigned int frontendProgressStart(
-	GPContext * /*context*/, float totalsize, const char *format, va_list args,
-	void *data
+	GPContext * /*context*/, float totalsize, const char *text, void *data
 ) {
 	KameraProtocol *object = (KameraProtocol*)data;
-	char *status;
-
-	/* We must copy the va_list to walk it twice, or all hell 
-	 * breaks loose on non-i386 platforms.
-	 */
-#if defined(HAVE_VA_COPY) || defined(HAVE___VA_COPY)
-	va_list xvalist;
-# ifdef HAVE_VA_COPY
-	va_copy(xvalist, args);
-# elif HAVE___VA_COPY
-	__va_copy(xvalist, args);
-# endif
-	int size=vsnprintf(NULL, 0, format, xvalist);
-	if(size<=0)
-		return GP_OK; // vsnprintf is broken, better don't do anything.
-
-	status=new char[size+1];
-# ifdef HAVE_VA_COPY
-	va_copy(xvalist, args);
-# elif HAVE___VA_COPY
-	__va_copy(xvalist, args);
-# endif
-	vsnprintf(status, size+1, format, xvalist);
-#else
-	/* We cannot copy the va_list, so make sure we 
-	 * walk it just _once_.
-	 */
-	status=new char[300];
-	vsnprintf(status, 300, format, args);
-#endif
 
-	object->infoMessage(QString::fromLocal8Bit(status));
-	delete [] status;
+	object->infoMessage(QString::fromLocal8Bit(text));
 	object->totalSize((int)totalsize); // hack: call slot directly
 	return GP_OK;
 }
 
 // this callback function is activated on every status message from gphoto2
-static void frontendCameraStatus(GPContext * /*context*/, const char *format, va_list args, void *data)
+static void frontendCameraStatus(GPContext * /*context*/, const char *text, void *data)
 {
 	KameraProtocol *object = (KameraProtocol*)data;
-	char *status;
 
 	/* We must copy the va_list to walk it twice, or all hell 
 	 * breaks loose on non-i386 platforms.
 	 */
-#if defined(HAVE_VA_COPY) || defined(HAVE___VA_COPY)
-	va_list xvalist;
-# ifdef HAVE_VA_COPY
-	va_copy(xvalist, args);
-# elif HAVE___VA_COPY
-	__va_copy(xvalist, args);
-# endif
-	int size=vsnprintf(NULL, 0, format, xvalist);
-	if(size<=0)
-		return; // vsnprintf is broken, better don't do anything.
-
-	status=new char[size+1];
-# ifdef HAVE_VA_COPY
-	va_copy(xvalist, args);
-# elif HAVE___VA_COPY
-	__va_copy(xvalist, args);
-# endif
-	vsnprintf(status, size+1, format, xvalist);
-#else
 	/* We cannot copy the va_list, so make sure we 
 	 * walk it just _once_.
 	 */
-	status=new char[300];
-	vsnprintf(status, 300, format, args);
-#endif
-	object->infoMessage(QString::fromLocal8Bit(status));
-	delete [] status;
+	object->infoMessage(QString::fromLocal8Bit(text));
 }
