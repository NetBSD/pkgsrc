$NetBSD: patch-.._.._ipxe_src_core_settings.c,v 1.1 2013/04/11 19:57:53 joerg Exp $

--- ../../ipxe/src/core/settings.c.orig	2013-03-25 18:48:57.000000000 +0000
+++ ../../ipxe/src/core/settings.c
@@ -263,10 +263,12 @@ static struct settings * find_child_sett
  */
 static struct settings * autovivify_child_settings ( struct settings *parent,
 						     const char *name ) {
+	size_t nlen = strlen ( name ) + 1 /* NUL */;
 	struct {
 		struct generic_settings generic;
-		char name[ strlen ( name ) + 1 /* NUL */ ];
+		char name[];
 	} *new_child;
+	size_t tlen = sizeof(*new_child) + nlen;
 	struct settings *settings;
 
 	/* Return existing settings, if existent */
@@ -274,13 +276,13 @@ static struct settings * autovivify_chil
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
 	generic_settings_init ( &new_child->generic, NULL, new_child->name );
 	settings = &new_child->generic.settings;
 	register_settings ( settings, parent );
