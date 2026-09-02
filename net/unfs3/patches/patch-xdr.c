$NetBSD: patch-xdr.c,v 1.1 2026/09/02 18:47:29 maya Exp $

Portability - libtirpc uses rpc/xdr.h from NetBSD

--- xdr.c.orig	2026-07-24 15:34:36.125979939 +0000
+++ xdr.c
@@ -160,14 +160,14 @@ bool_t xdr_nfspath3(XDR * xdrs, nfspath3
 
 bool_t xdr_fileid3(XDR * xdrs, fileid3 * objp)
 {
-    if (!xdr_uint64_t(xdrs, objp))
+    if (!xdr_u_int64_t(xdrs, objp))
         return FALSE;
     return TRUE;
 }
 
 bool_t xdr_cookie3(XDR * xdrs, cookie3 * objp)
 {
-    if (!xdr_uint64_t(xdrs, objp))
+    if (!xdr_u_int64_t(xdrs, objp))
         return FALSE;
     return TRUE;
 }
@@ -195,42 +195,42 @@ bool_t xdr_writeverf3(XDR * xdrs, writev
 
 bool_t xdr_uid3(XDR * xdrs, uid3 * objp)
 {
-    if (!xdr_uint32_t(xdrs, objp))
+    if (!xdr_u_int32_t(xdrs, objp))
         return FALSE;
     return TRUE;
 }
 
 bool_t xdr_gid3(XDR * xdrs, gid3 * objp)
 {
-    if (!xdr_uint32_t(xdrs, objp))
+    if (!xdr_u_int32_t(xdrs, objp))
         return FALSE;
     return TRUE;
 }
 
 bool_t xdr_size3(XDR * xdrs, size3 * objp)
 {
-    if (!xdr_uint64_t(xdrs, objp))
+    if (!xdr_u_int64_t(xdrs, objp))
         return FALSE;
     return TRUE;
 }
 
 bool_t xdr_offset3(XDR * xdrs, offset3 * objp)
 {
-    if (!xdr_uint64_t(xdrs, objp))
+    if (!xdr_u_int64_t(xdrs, objp))
         return FALSE;
     return TRUE;
 }
 
 bool_t xdr_mode3(XDR * xdrs, mode3 * objp)
 {
-    if (!xdr_uint32_t(xdrs, objp))
+    if (!xdr_u_int32_t(xdrs, objp))
         return FALSE;
     return TRUE;
 }
 
 bool_t xdr_count3(XDR * xdrs, count3 * objp)
 {
-    if (!xdr_uint32_t(xdrs, objp))
+    if (!xdr_u_int32_t(xdrs, objp))
         return FALSE;
     return TRUE;
 }
@@ -251,9 +251,9 @@ bool_t xdr_ftype3(XDR * xdrs, ftype3 * o
 
 bool_t xdr_specdata3(XDR * xdrs, specdata3 * objp)
 {
-    if (!xdr_uint32_t(xdrs, &objp->specdata1))
+    if (!xdr_u_int32_t(xdrs, &objp->specdata1))
         return FALSE;
-    if (!xdr_uint32_t(xdrs, &objp->specdata2))
+    if (!xdr_u_int32_t(xdrs, &objp->specdata2))
         return FALSE;
     return TRUE;
 }
@@ -269,9 +269,9 @@ bool_t xdr_nfs_fh3(XDR * xdrs, nfs_fh3 *
 
 bool_t xdr_nfstime3(XDR * xdrs, nfstime3 * objp)
 {
-    if (!xdr_uint32_t(xdrs, &objp->seconds))
+    if (!xdr_u_int32_t(xdrs, &objp->seconds))
         return FALSE;
-    if (!xdr_uint32_t(xdrs, &objp->nseconds))
+    if (!xdr_u_int32_t(xdrs, &objp->nseconds))
         return FALSE;
     return TRUE;
 }
@@ -282,7 +282,7 @@ bool_t xdr_fattr3(XDR * xdrs, fattr3 * o
         return FALSE;
     if (!xdr_mode3(xdrs, &objp->mode))
         return FALSE;
-    if (!xdr_uint32_t(xdrs, &objp->nlink))
+    if (!xdr_u_int32_t(xdrs, &objp->nlink))
         return FALSE;
     if (!xdr_uid3(xdrs, &objp->uid))
         return FALSE;
@@ -294,7 +294,7 @@ bool_t xdr_fattr3(XDR * xdrs, fattr3 * o
         return FALSE;
     if (!xdr_specdata3(xdrs, &objp->rdev))
         return FALSE;
-    if (!xdr_uint64_t(xdrs, &objp->fsid))
+    if (!xdr_u_int64_t(xdrs, &objp->fsid))
         return FALSE;
     if (!xdr_fileid3(xdrs, &objp->fileid))
         return FALSE;
@@ -635,7 +635,7 @@ bool_t xdr_ACCESS3args(XDR * xdrs, ACCES
 {
     if (!xdr_nfs_fh3(xdrs, &objp->object))
         return FALSE;
-    if (!xdr_uint32_t(xdrs, &objp->access))
+    if (!xdr_u_int32_t(xdrs, &objp->access))
         return FALSE;
     return TRUE;
 }
@@ -644,7 +644,7 @@ bool_t xdr_ACCESS3resok(XDR * xdrs, ACCE
 {
     if (!xdr_post_op_attr(xdrs, &objp->obj_attributes))
         return FALSE;
-    if (!xdr_uint32_t(xdrs, &objp->access))
+    if (!xdr_u_int32_t(xdrs, &objp->access))
         return FALSE;
     return TRUE;
 }
@@ -1408,7 +1408,7 @@ bool_t xdr_FSSTAT3resok(XDR * xdrs, FSST
         return FALSE;
     if (!xdr_size3(xdrs, &objp->afiles))
         return FALSE;
-    if (!xdr_uint32_t(xdrs, &objp->invarsec))
+    if (!xdr_u_int32_t(xdrs, &objp->invarsec))
         return FALSE;
     return TRUE;
 }
@@ -1448,25 +1448,25 @@ bool_t xdr_FSINFO3resok(XDR * xdrs, FSIN
 {
     if (!xdr_post_op_attr(xdrs, &objp->obj_attributes))
         return FALSE;
-    if (!xdr_uint32_t(xdrs, &objp->rtmax))
+    if (!xdr_u_int32_t(xdrs, &objp->rtmax))
         return FALSE;
-    if (!xdr_uint32_t(xdrs, &objp->rtpref))
+    if (!xdr_u_int32_t(xdrs, &objp->rtpref))
         return FALSE;
-    if (!xdr_uint32_t(xdrs, &objp->rtmult))
+    if (!xdr_u_int32_t(xdrs, &objp->rtmult))
         return FALSE;
-    if (!xdr_uint32_t(xdrs, &objp->wtmax))
+    if (!xdr_u_int32_t(xdrs, &objp->wtmax))
         return FALSE;
-    if (!xdr_uint32_t(xdrs, &objp->wtpref))
+    if (!xdr_u_int32_t(xdrs, &objp->wtpref))
         return FALSE;
-    if (!xdr_uint32_t(xdrs, &objp->wtmult))
+    if (!xdr_u_int32_t(xdrs, &objp->wtmult))
         return FALSE;
-    if (!xdr_uint32_t(xdrs, &objp->dtpref))
+    if (!xdr_u_int32_t(xdrs, &objp->dtpref))
         return FALSE;
     if (!xdr_size3(xdrs, &objp->maxfilesize))
         return FALSE;
     if (!xdr_nfstime3(xdrs, &objp->time_delta))
         return FALSE;
-    if (!xdr_uint32_t(xdrs, &objp->properties))
+    if (!xdr_u_int32_t(xdrs, &objp->properties))
         return FALSE;
     return TRUE;
 }
@@ -1506,9 +1506,9 @@ bool_t xdr_PATHCONF3resok(XDR * xdrs, PA
 {
     if (!xdr_post_op_attr(xdrs, &objp->obj_attributes))
         return FALSE;
-    if (!xdr_uint32_t(xdrs, &objp->linkmax))
+    if (!xdr_u_int32_t(xdrs, &objp->linkmax))
         return FALSE;
-    if (!xdr_uint32_t(xdrs, &objp->name_max))
+    if (!xdr_u_int32_t(xdrs, &objp->name_max))
         return FALSE;
     if (!xdr_bool(xdrs, &objp->no_trunc))
         return FALSE;
