$NetBSD: patch-.._.._ipxe_src_core_settings.c,v 1.1.1.1 2016/07/04 07:30:49 jnemeth Exp $

--- ../../ipxe/src/core/settings.c.orig	2013-03-25 18:48:57.000000000 +0000
+++ ../../ipxe/src/core/settings.c
@@ -284,10 +284,12 @@ static struct settings * find_child_sett
  */
 static struct settings * autovivify_child_settings ( struct settings *parent,
 						     const char *name ) {
+	size_t nlen = strlen(name) + 1;
 	struct {
 		struct autovivified_settings autovivified;
-		char name[ strlen ( name ) + 1 /* NUL */ ];
+		char name[];
 	} *new_child;
+	size_t tlen = sizeof(*new_child) + nlen;
 	struct settings *settings;
 
 	/* Return existing settings, if existent */
@@ -295,13 +297,13 @@ static struct settings * autovivify_chil
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
