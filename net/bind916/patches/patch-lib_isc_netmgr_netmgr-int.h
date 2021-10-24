$NetBSD: patch-lib_isc_netmgr_netmgr-int.h,v 1.1 2021/10/24 06:40:28 taca Exp $

* Take from NetBSD base.

--- lib/isc/netmgr/netmgr-int.h.orig	2021-09-07 09:37:05.000000000 +0000
+++ lib/isc/netmgr/netmgr-int.h
@@ -377,13 +377,13 @@ typedef struct isc__netievent__socket {
 } isc__netievent__socket_t;
 
 #define NETIEVENT_SOCKET_TYPE(type) \
-	typedef isc__netievent__socket_t isc__netievent_##type##_t;
+	typedef isc__netievent__socket_t isc__netievent_##type##_t
 
 #define NETIEVENT_SOCKET_DECL(type)                              \
 	isc__netievent_##type##_t *isc__nm_get_netievent_##type( \
 		isc_nm_t *nm, isc_nmsocket_t *sock);             \
 	void isc__nm_put_netievent_##type(isc_nm_t *nm,          \
-					  isc__netievent_##type##_t *ievent);
+					  isc__netievent_##type##_t *ievent)
 
 #define NETIEVENT_SOCKET_DEF(type)                                             \
 	isc__netievent_##type##_t *isc__nm_get_netievent_##type(               \
@@ -407,13 +407,13 @@ typedef struct isc__netievent__socket_re
 } isc__netievent__socket_req_t;
 
 #define NETIEVENT_SOCKET_REQ_TYPE(type) \
-	typedef isc__netievent__socket_req_t isc__netievent_##type##_t;
+	typedef isc__netievent__socket_req_t isc__netievent_##type##_t
 
 #define NETIEVENT_SOCKET_REQ_DECL(type)                                    \
 	isc__netievent_##type##_t *isc__nm_get_netievent_##type(           \
 		isc_nm_t *nm, isc_nmsocket_t *sock, isc__nm_uvreq_t *req); \
 	void isc__nm_put_netievent_##type(isc_nm_t *nm,                    \
-					  isc__netievent_##type##_t *ievent);
+					  isc__netievent_##type##_t *ievent)
 
 #define NETIEVENT_SOCKET_REQ_DEF(type)                                         \
 	isc__netievent_##type##_t *isc__nm_get_netievent_##type(               \
@@ -440,14 +440,14 @@ typedef struct isc__netievent__socket_re
 } isc__netievent__socket_req_result_t;
 
 #define NETIEVENT_SOCKET_REQ_RESULT_TYPE(type) \
-	typedef isc__netievent__socket_req_result_t isc__netievent_##type##_t;
+	typedef isc__netievent__socket_req_result_t isc__netievent_##type##_t
 
 #define NETIEVENT_SOCKET_REQ_RESULT_DECL(type)                            \
 	isc__netievent_##type##_t *isc__nm_get_netievent_##type(          \
 		isc_nm_t *nm, isc_nmsocket_t *sock, isc__nm_uvreq_t *req, \
 		isc_result_t result);                                     \
 	void isc__nm_put_netievent_##type(isc_nm_t *nm,                   \
-					  isc__netievent_##type##_t *ievent);
+					  isc__netievent_##type##_t *ievent)
 
 #define NETIEVENT_SOCKET_REQ_RESULT_DEF(type)                                  \
 	isc__netievent_##type##_t *isc__nm_get_netievent_##type(               \
@@ -474,13 +474,13 @@ typedef struct isc__netievent__socket_ha
 } isc__netievent__socket_handle_t;
 
 #define NETIEVENT_SOCKET_HANDLE_TYPE(type) \
-	typedef isc__netievent__socket_handle_t isc__netievent_##type##_t;
+	typedef isc__netievent__socket_handle_t isc__netievent_##type##_t
 
 #define NETIEVENT_SOCKET_HANDLE_DECL(type)                                   \
 	isc__netievent_##type##_t *isc__nm_get_netievent_##type(             \
 		isc_nm_t *nm, isc_nmsocket_t *sock, isc_nmhandle_t *handle); \
 	void isc__nm_put_netievent_##type(isc_nm_t *nm,                      \
-					  isc__netievent_##type##_t *ievent);
+					  isc__netievent_##type##_t *ievent)
 
 #define NETIEVENT_SOCKET_HANDLE_DEF(type)                                      \
 	isc__netievent_##type##_t *isc__nm_get_netievent_##type(               \
@@ -506,13 +506,13 @@ typedef struct isc__netievent__socket_qu
 } isc__netievent__socket_quota_t;
 
 #define NETIEVENT_SOCKET_QUOTA_TYPE(type) \
-	typedef isc__netievent__socket_quota_t isc__netievent_##type##_t;
+	typedef isc__netievent__socket_quota_t isc__netievent_##type##_t
 
 #define NETIEVENT_SOCKET_QUOTA_DECL(type)                                \
 	isc__netievent_##type##_t *isc__nm_get_netievent_##type(         \
 		isc_nm_t *nm, isc_nmsocket_t *sock, isc_quota_t *quota); \
 	void isc__nm_put_netievent_##type(isc_nm_t *nm,                  \
-					  isc__netievent_##type##_t *ievent);
+					  isc__netievent_##type##_t *ievent)
 
 #define NETIEVENT_SOCKET_QUOTA_DEF(type)                                       \
 	isc__netievent_##type##_t *isc__nm_get_netievent_##type(               \
@@ -571,12 +571,12 @@ typedef struct isc__netievent {
 	isc__netievent_type type;
 } isc__netievent_t;
 
-#define NETIEVENT_TYPE(type) typedef isc__netievent_t isc__netievent_##type##_t;
+#define NETIEVENT_TYPE(type) typedef isc__netievent_t isc__netievent_##type##_t
 
 #define NETIEVENT_DECL(type)                                                   \
 	isc__netievent_##type##_t *isc__nm_get_netievent_##type(isc_nm_t *nm); \
 	void isc__nm_put_netievent_##type(isc_nm_t *nm,                        \
-					  isc__netievent_##type##_t *ievent);
+					  isc__netievent_##type##_t *ievent)
 
 #define NETIEVENT_DEF(type)                                                    \
 	isc__netievent_##type##_t *isc__nm_get_netievent_##type(               \
