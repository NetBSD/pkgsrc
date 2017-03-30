$NetBSD: patch-.._ipxe_src_core_settings.c,v 1.1 2017/03/30 09:15:10 bouyer Exp $

--- ../ipxe/src/core/settings.c.orig	2016-08-31 18:23:42.000000000 +0200
+++ ../ipxe/src/core/settings.c	2017-03-24 19:44:07.000000000 +0100
@@ -304,10 +304,12 @@
  */
 struct settings * autovivify_child_settings ( struct settings *parent,
 					      const char *name ) {
+	size_t nlen = strlen(name) + 1;
 	struct {
 		struct autovivified_settings autovivified;
-		char name[ strlen ( name ) + 1 /* NUL */ ];
+		char name[];
 	} *new_child;
+	size_t tlen = sizeof(*new_child) + nlen;
 	struct settings *settings;
 
 	/* Find target parent settings block */
@@ -318,13 +320,13 @@
 		return settings;
 
 	/* Create new generic settings block */
-	new_child = zalloc ( sizeof ( *new_child ) );
+	new_child = zalloc ( tlen );
 	if ( ! new_child ) {
 		DBGC ( parent, "Settings %p could not create child %s\n",
 		       parent, name );
 		return NULL;
 	}
-	memcpy ( new_child->name, name, sizeof ( new_child->name ) );
+	memcpy ( new_child->name, name, nlen );
 	ref_init ( &new_child->autovivified.refcnt,
 		   autovivified_settings_free );
 	generic_settings_init ( &new_child->autovivified.generic,
