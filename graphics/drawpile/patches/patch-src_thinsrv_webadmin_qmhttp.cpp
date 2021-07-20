$NetBSD: patch-src_thinsrv_webadmin_qmhttp.cpp,v 1.1 2021/07/20 10:54:18 nia Exp $

Compatibility with libmicrohttpd-0.9.71

--- src/thinsrv/webadmin/qmhttp.cpp.orig	2020-02-16 16:35:42.000000000 +0000
+++ src/thinsrv/webadmin/qmhttp.cpp
@@ -30,6 +30,20 @@
 
 #include <microhttpd.h>
 
+/*
+ * In version 0.9.71 of libmicrohttpd, MHD_YES and MHD_NO have been changed
+ * from being #defines to being enum values. Several callback types have also
+ * changed from returning an int to returning an MHD_Result.
+ *
+ * That's fine in C, but it actually breaks in C++ and errors out, so we have
+ * to add this compatibility shim to make things work again.
+ *
+ * https://lists.gnu.org/archive/html/libmicrohttpd/2020-06/msg00013.html
+ */
+#if MHD_VERSION < 0x00097002
+typedef int MHD_Result;
+#endif
+
 static const char *MSG_401 = "<html><body>401 - Unauthorized</body></html>";
 static const char *MSG_404 = "<html><body>404 - Page not found</body></html>";
 
@@ -80,7 +94,7 @@ static void logMessage(MHD_Connection *c
 			statusCode, qPrintable(clientAddress.toString()), method, url);
 }
 
-int iterate_post(void *con_cls, enum MHD_ValueKind kind, const char *key, const char *filename, const char *content_type, const char *transfer_encoding, const char *data, uint64_t off, size_t size)
+MHD_Result iterate_post(void *con_cls, enum MHD_ValueKind kind, const char *key, const char *filename, const char *content_type, const char *transfer_encoding, const char *data, uint64_t off, size_t size)
 {
 	Q_UNUSED(kind);
 	Q_UNUSED(filename);
@@ -97,7 +111,7 @@ int iterate_post(void *con_cls, enum MHD
 	return MHD_YES;
 }
 
-int assign_to_hash(void *cls, enum MHD_ValueKind kind, const char *key, const char *value)
+MHD_Result assign_to_hash(void *cls, enum MHD_ValueKind kind, const char *key, const char *value)
 {
 	Q_UNUSED(kind);
 	QHash<QString,QString> *hash = reinterpret_cast<QHash<QString,QString>*>(cls);
@@ -117,7 +131,7 @@ void request_completed(void *cls, struct
 	*con_cls = nullptr;
 }
 
-int request_handler(void *cls, MHD_Connection *connection, const char *url, const char *methodstr, const char *version, const char *upload_data, size_t *upload_data_size, void **con_cls)
+MHD_Result request_handler(void *cls, MHD_Connection *connection, const char *url, const char *methodstr, const char *version, const char *upload_data, size_t *upload_data_size, void **con_cls)
 {
 	Q_UNUSED(version);
 	MicroHttpd::Private *d = reinterpret_cast<MicroHttpd::Private*>(cls);
@@ -212,7 +226,7 @@ int request_handler(void *cls, MHD_Conne
 						response);
 				}
 				MHD_destroy_response(response);
-				return ret;
+				return ret ? MHD_YES : MHD_NO;
 			}
 		}
 
@@ -277,7 +291,7 @@ int request_handler(void *cls, MHD_Conne
 	return ret;
 }
 
-int access_policy(void *cls, const struct sockaddr * addr, socklen_t addrlen)
+MHD_Result access_policy(void *cls, const struct sockaddr * addr, socklen_t addrlen)
 {
 	Q_UNUSED(addrlen);
 	MicroHttpd::Private *d = reinterpret_cast<MicroHttpd::Private*>(cls);
