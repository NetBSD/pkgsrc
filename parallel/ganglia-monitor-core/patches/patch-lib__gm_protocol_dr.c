$NetBSD: patch-lib__gm_protocol_dr.c,v 1.1 2012/03/13 12:36:25 fhajny Exp $

Use INT32 macros, LONG ones were taken out of LP64 on Solaris.
--- lib/gm_protocol_xdr.c.orig	2009-01-28 23:23:20.000000000 +0000
+++ lib/gm_protocol_xdr.c
@@ -53,9 +53,9 @@ xdr_Ganglia_metadata_message (XDR *xdrs,
 				 return FALSE;
 
 		} else {
-		IXDR_PUT_U_LONG(buf, objp->slope);
-		IXDR_PUT_U_LONG(buf, objp->tmax);
-		IXDR_PUT_U_LONG(buf, objp->dmax);
+		IXDR_PUT_U_INT32(buf, objp->slope);
+		IXDR_PUT_U_INT32(buf, objp->tmax);
+		IXDR_PUT_U_INT32(buf, objp->dmax);
 		}
 		 if (!xdr_array (xdrs, (char **)&objp->metadata.metadata_val, (u_int *) &objp->metadata.metadata_len, ~0,
 			sizeof (Ganglia_extra_data), (xdrproc_t) xdr_Ganglia_extra_data))
@@ -78,9 +78,9 @@ xdr_Ganglia_metadata_message (XDR *xdrs,
 				 return FALSE;
 
 		} else {
-		objp->slope = IXDR_GET_U_LONG(buf);
-		objp->tmax = IXDR_GET_U_LONG(buf);
-		objp->dmax = IXDR_GET_U_LONG(buf);
+		objp->slope = IXDR_GET_U_INT32(buf);
+		objp->tmax = IXDR_GET_U_INT32(buf);
+		objp->dmax = IXDR_GET_U_INT32(buf);
 		}
 		 if (!xdr_array (xdrs, (char **)&objp->metadata.metadata_val, (u_int *) &objp->metadata.metadata_len, ~0,
 			sizeof (Ganglia_extra_data), (xdrproc_t) xdr_Ganglia_extra_data))
