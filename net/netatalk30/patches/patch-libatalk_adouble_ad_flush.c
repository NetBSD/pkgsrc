$NetBSD: patch-libatalk_adouble_ad_flush.c,v 1.1 2014/06/28 04:41:55 markd Exp $

fd leak when using appledouble = v2, netatalk bug 554

--- libatalk/adouble/ad_flush.c.orig	2013-04-09 12:56:18.000000000 +0000
+++ libatalk/adouble/ad_flush.c
@@ -429,6 +429,17 @@ int ad_close(struct adouble *ad, int adf
     }
 
     if (adflags & ADFLAGS_RF) {
+        /* HF is automatically opened when opening an RF, close it. */
+        if ((ad->ad_vers == AD_VERSION2) && (ad_meta_fileno(ad) != -1)) {
+            if (ad->ad_meta_refcount)
+                ad->ad_meta_refcount--;
+            if (!(--ad->ad_mdp->adf_refcount)) {
+                if (close( ad_meta_fileno(ad)) < 0)
+                    err = -1;
+                ad_meta_fileno(ad) = -1;
+            }
+        }
+
         if (ad->ad_reso_refcount)
             if (--ad->ad_reso_refcount == 0)
                 adf_lock_free(ad->ad_rfp);
