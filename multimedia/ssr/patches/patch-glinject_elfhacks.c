$NetBSD: patch-glinject_elfhacks.c,v 1.1 2016/02/08 20:43:32 markd Exp $

NetBSD doesn't know about DT_GNU_HASH

--- glinject/elfhacks.c.orig	2015-11-02 21:13:49.000000000 +0000
+++ glinject/elfhacks.c
@@ -198,11 +198,13 @@ int eh_init_obj(eh_obj_t *obj)
 				return ENOTSUP;
 
 			obj->hash = (ElfW(Word) *) obj->dynamic[p].d_un.d_ptr;
+#ifdef DT_GNU_HASH
 		} else if (obj->dynamic[p].d_tag == DT_GNU_HASH) {
 			if (obj->gnu_hash)
 				return ENOTSUP;
 
 			obj->gnu_hash = (Elf32_Word *) obj->dynamic[p].d_un.d_ptr;
+#endif
 		} else if (obj->dynamic[p].d_tag == DT_SYMTAB) {
 			if (obj->symtab)
 				return ENOTSUP;
