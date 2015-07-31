$NetBSD: patch-src_cmd_ld_data.c,v 1.1 2015/07/31 14:46:25 bsiegert Exp $

Support cgo on illumos.

--- src/cmd/ld/data.c.orig	2014-12-11 01:18:12.000000000 +0000
+++ src/cmd/ld/data.c
@@ -965,6 +965,46 @@ dodata(void)
 	datap = listsort(datap, datcmp, offsetof(LSym, next));
 
 	/*
+	 * The SunOS rtld expects the .rel/.rela and .rel.plt/.rela.plt
+	 * sections to be contiguous.  More properly, it expects that the
+	 * region starting from the lower of DT_RELA and DT_PLTREL and
+	 * continuing for DT_RELASZ bytes contains at least the set of non-PLT
+	 * relocation entries.  To ensure this, we put .rel[a].plt after .rel[a].
+	 * This is actually required by the ELF gABI on all ELF platforms.
+	 */
+	if (ctxt->headtype == Hsolaris) {
+		for (l = &datap; (s = *l) != nil; ) {
+			if (strcmp(s->name, ".rel.plt") == 0 ||
+			    strcmp(s->name, ".rela.plt") == 0) {
+				*l = s->next;
+				s->next = nil;
+				last = s;
+				break;
+			}
+			l = &s->next;
+		}
+
+		if (s != nil) {
+			for (s = datap; s != nil; s = s->next) {
+				if (strcmp(s->name, ".rel") == 0 ||
+				    strcmp(s->name, ".rela") == 0) {
+					last->next = s->next;
+					s->next = last;
+					break;
+				}
+			}
+			/*
+			 * .rel[a].plt without .rel[a].  Should never occur
+			 * but just in case, put it back where we found it.
+			 */
+			if (s == nil) {
+				last->next = (*l)->next;
+				(*l)->next = last;
+			}
+		}
+	}
+
+	/*
 	 * allocate sections.  list is sorted by type,
 	 * so we can just walk it for each piece we want to emit.
 	 * segdata is processed before segtext, because we need
@@ -1239,6 +1279,85 @@ dodata(void)
 		sect->extnum = n++;
 }
 
+/*
+ * Fix up the section numbers in .dynsym if present.  We could not write these
+ * shndx entries until we know all present sections and have sorted them.
+ *
+ * Each dynsym entry is actually an ElfXX_Sym, and we're going to replace the
+ * st_shndx field.  For 32-bit targets, that's at offset 0xe; for 64-bit, it's
+ * at offset 0x6.  Anything we don't expect, we ignore and leave unchanged.
+ */
+void
+dodynsym(void)
+{
+	LSym *ds;
+	LSym *ss;
+	LSym *s;
+	vlong off;
+	size_t entsz;
+	uint16 ent;
+	char *sectname = nil;
+
+	if (!iself)
+		return;
+
+	ds = linklookup(ctxt, ".dynsym", 0);
+
+	if (ds == nil)
+		return;
+
+	if (thechar == '6')
+		entsz = ELF64SYMSIZE;
+	else
+		entsz = ELF32SYMSIZE;
+
+	for(s = ctxt->allsym; s != nil; s = s->allsym) {
+		if (s->dynid <= 0 || s->type == SDYNIMPORT)
+			continue;
+
+		if (s->sect != nil) {
+			ent = s->sect->extnum;
+		} else {
+			switch (s->type) {
+			case STEXT:
+			default:
+				sectname = ".text";
+				break;
+			case SRODATA:
+				sectname = ".rodata";
+				break;
+			case SDATA:
+				sectname = ".data";
+				break;
+			case SBSS:
+				sectname = ".bss";
+				break;
+			}
+
+			ss = linklookup(ctxt, sectname, 0);
+			if (ss == nil || ss->sect == nil) {
+				diag("dodynsym: symbol %s in nonexistent %s",
+				    s->extname != nil ? s->extname : "<none>",
+				    sectname);
+				continue;
+			}
+
+			ent = ss->sect->extnum;
+		}
+
+		if (ent == 0) {
+			diag("dodynsym: symbol %s in section 0; ignored");
+			continue;
+		}
+
+		off = s->dynid * entsz +
+		    ((thechar == '6') ? offsetof(Elf64_Sym, shndx) :
+		    offsetof(Elf32_Sym, shndx));
+
+		(void) setuint16(ctxt, ds, off, ent);
+	}
+}
+
 // assign addresses to text
 void
 textaddress(void)
