$NetBSD: patch-lib_elf__py.c,v 1.1 2021/08/11 10:09:54 kardel Exp $

	frr 8 now embeds Xref information in executables and
	adds notes to the ELF files. On NetBSD these notes
	create kernel messages at exec time. Allow the
	note mechanism to be disabled by allowing lib/elf_py.c
	to be compiled in that configuration.

--- lib/elf_py.c.orig	2021-08-06 11:34:16.683867232 +0000
+++ lib/elf_py.c
@@ -1030,6 +1030,7 @@ static char *elfdata_strptr(Elf_Data *da
 	return p;
 }
 
+#ifdef HAVE_ELF_GETDATA_RAWCHUNK
 static void elffile_add_dynreloc(struct elffile *w, Elf_Data *reldata,
 				 size_t entries, Elf_Data *symdata,
 				 Elf_Data *strdata, Elf_Type typ)
@@ -1124,6 +1125,7 @@ static void elffile_add_dynreloc(struct 
 	}
 
 }
+#endif
 
 /* primary (only, really) entry point to anything in this module */
 static PyObject *elffile_load(PyTypeObject *type, PyObject *args,
