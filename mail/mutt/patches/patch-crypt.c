$NetBSD: patch-crypt.c,v 1.1 2016/02/22 12:13:26 wiz Exp $

# HG changeset patch
# User Kevin McCarthy <kevin@8t8.us>
# Date 1449022827 28800
#      Tue Dec 01 18:20:27 2015 -0800
# Node ID 5e5aff1782dc62044197c2230d346bd492706fbf
# Parent  428a92464d5bccccda818bed598610db212fcf7c
Loosen mutt_signed_handler() protocol value consistency check.  (closes #3639)

Apparently, for S/MIME, some MUAs mismatch the protocol value of
the multipart/signed and the content-type of the signature: putting
"pkcs7-signature" in one and "x-pkcs7-signature" in the other.

Change mutt_signed_handler() to independently verify the values of the
protocol and the content-type.  This still checks for correct values but
doesn't ensure they match between the two (for S/MIME).

--- crypt.c.orig	2013-02-06 13:22:15.000000000 +0000
+++ crypt.c
@@ -772,9 +772,8 @@ static void crypt_fetch_signatures (BODY
 int mutt_signed_handler (BODY *a, STATE *s)
 {
   char tempfile[_POSIX_PATH_MAX];
-  char *protocol;
-  int protocol_major = TYPEOTHER;
-  char *protocol_minor = NULL;
+  int signed_type;
+  int inconsistent = 0;
   
   BODY *b = a;
   BODY **signatures = NULL;
@@ -786,29 +785,44 @@ int mutt_signed_handler (BODY *a, STATE 
   if (!WithCrypto)
     return -1;
 
-  protocol = mutt_get_parameter ("protocol", a->parameter);
   a = a->parts;
-
-  /* extract the protocol information */
-  
-  if (protocol)
+  signed_type = mutt_is_multipart_signed (b);
+  if (!signed_type)
   {
-    char major[STRING];
-    char *t;
-
-    if ((protocol_minor = strchr (protocol, '/'))) protocol_minor++;
-    
-    strfcpy (major, protocol, sizeof(major));
-    if((t = strchr(major, '/')))
-      *t = '\0';
-    
-    protocol_major = mutt_check_mime_type (major);
+    /* A null protocol value is already checked for in mutt_body_handler() */
+    state_printf (s, _("[-- Error: "
+                       "Unknown multipart/signed protocol %s! --]\n\n"),
+                  mutt_get_parameter ("protocol", b->parameter));
+    return mutt_body_handler (a, s);
   }
 
-  /* consistency check */
-
-  if (!(a && a->next && a->next->type == protocol_major && 
-      !mutt_strcasecmp (a->next->subtype, protocol_minor)))
+  if (!(a && a->next))
+    inconsistent = 1;
+  else
+  {
+    switch (signed_type)
+    {
+      case SIGN:
+        if (a->next->type != TYPEMULTIPART ||
+            ascii_strcasecmp (a->next->subtype, "mixed"))
+          inconsistent = 1;
+        break;
+      case PGPSIGN:
+        if (a->next->type != TYPEAPPLICATION ||
+            ascii_strcasecmp (a->next->subtype, "pgp-signature"))
+          inconsistent = 1;
+        break;
+      case SMIMESIGN:
+        if (a->next->type != TYPEAPPLICATION ||
+            (ascii_strcasecmp (a->next->subtype, "x-pkcs7-signature") &&
+             ascii_strcasecmp (a->next->subtype, "pkcs7-signature")))
+          inconsistent = 1;
+        break;
+      default:
+        inconsistent = 1;
+    }
+  }
+  if (inconsistent)
   {
     state_attach_puts (_("[-- Error: "
                          "Inconsistent multipart/signed structure! --]\n\n"),
@@ -816,27 +830,6 @@ int mutt_signed_handler (BODY *a, STATE 
     return mutt_body_handler (a, s);
   }
 
-  
-  if ((WithCrypto & APPLICATION_PGP)
-      && protocol_major == TYPEAPPLICATION
-      && !ascii_strcasecmp (protocol_minor, "pgp-signature"))
-    ;
-  else if ((WithCrypto & APPLICATION_SMIME)
-           && protocol_major == TYPEAPPLICATION
-	   && !(ascii_strcasecmp (protocol_minor, "x-pkcs7-signature")
-	       && ascii_strcasecmp (protocol_minor, "pkcs7-signature")))
-    ;
-  else if (protocol_major == TYPEMULTIPART
-	   && !ascii_strcasecmp (protocol_minor, "mixed"))
-    ;
-  else
-  {
-    state_printf (s, _("[-- Error: "
-                       "Unknown multipart/signed protocol %s! --]\n\n"),
-                  protocol);
-    return mutt_body_handler (a, s);
-  }
-  
   if (s->flags & M_DISPLAY)
   {
     
