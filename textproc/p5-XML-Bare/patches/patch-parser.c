$NetBSD: patch-parser.c,v 1.1 2025/07/02 03:52:04 markd Exp $

assignment to 'char *' from 'int' makes pointer from integer without a cast

--- parser.c.orig	2013-07-12 15:23:43.000000000 +0000
+++ parser.c
@@ -419,7 +419,7 @@ int parserc_parse( struct parserc *self,
         case 0: last_state = ST_att_name; goto done;
         case '/': // self closing     !! /> is assumed !!
           curatt = nodec_addattr( curnode, attname, attname_len );
-          if( !att_has_val ) { curatt->value = -1; curatt->vallen = 0; }
+          if( !att_has_val ) { curatt->value = (char *) -1; curatt->vallen = 0; }
           attname_len            = 0;
           
           curnode->z = cpos+1-xmlin;
@@ -438,7 +438,7 @@ int parserc_parse( struct parserc *self,
           goto att_space;
         case '>':
           curatt = nodec_addattr( curnode, attname, attname_len );
-          if( !att_has_val ) { curatt->value = -1; curatt->vallen = 0; }
+          if( !att_has_val ) { curatt->value = (char *) -1; curatt->vallen = 0; }
           attname_len = 0;
           cpos++;
           goto val_1;
@@ -834,7 +834,7 @@ int parserc_parse_unsafely( struct parse
       switch( let ) {
         case '/': // self closing     !! /> is assumed !!
           curatt = nodec_addattr( curnode, attname, attname_len );
-          if( !att_has_val ) { curatt->value = -1; curatt->vallen = 0; }
+          if( !att_has_val ) { curatt->value = (char *) -1; curatt->vallen = 0; }
           attname_len = 0;
           
           curnode = curnode->parent;
@@ -852,7 +852,7 @@ int parserc_parse_unsafely( struct parse
           goto u_att_space;
         case '>':
           curatt = nodec_addattr( curnode, attname, attname_len );
-          if( !att_has_val ) { curatt->value = -1; curatt->vallen = 0; }
+          if( !att_has_val ) { curatt->value = (char *) -1; curatt->vallen = 0; }
           attname_len = 0;
           cpos++;
           goto u_val_1;
