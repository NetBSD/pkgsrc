$NetBSD: patch-coda-src_venus_vproc_vfscalls.cc,v 1.1 2015/01/27 15:21:52 hauke Exp $

The .vtype struct field is not declared for SunOS.

--- ./coda-src/venus/vproc_vfscalls.cc.orig	2009-02-13 20:50:21.000000000 +0000
+++ ./coda-src/venus/vproc_vfscalls.cc
@@ -124,7 +124,9 @@ void vproc::vget(struct venus_cnode *vpp
 	worker *w = (worker *)this;
 	union outputArgs *out = (union outputArgs *)w->msg->msg_buf;
 	out->coda_vget.Fid = *VenusToKernelFid(&cfidp->cfid_fid);
+#ifdef CDT_UNKNOWN
 	out->coda_vget.vtype = CDT_UNKNOWN;
+#endif        
 	w->Return(w->msg, sizeof(struct coda_vget_out));
     }
 
