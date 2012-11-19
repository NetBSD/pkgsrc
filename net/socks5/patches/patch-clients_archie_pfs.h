$NetBSD: patch-clients_archie_pfs.h,v 1.1 2012/11/19 02:59:39 joerg Exp $

--- clients/archie/pfs.h.orig	2012-11-18 22:48:11.000000000 +0000
+++ clients/archie/pfs.h
@@ -194,7 +194,7 @@ struct acl {
     char		*atype;           /* Authentication type            */
     char		*rights;          /* Rights                         */
     char		*principals;      /* Authorized principals          */
-    struct restrict     *restrictions;    /* Restrictions on use            */
+    struct restrictions *restrictions;    /* Restrictions on use            */
     struct acl		*previous;        /* Previous elt in linked list    */
     struct acl		*next;		  /* Next element in linked list    */
 };
@@ -216,7 +216,7 @@ typedef struct acl ACL_ST;
 
 /* Definition of structure contining access restrictions */
 /* for future extensions                                 */
-struct restrict {
+struct restrictions {
     struct acl		*previous;        /* Previous elt in linked list    */
     struct acl		*next;		  /* Next element in linked list    */
 };
