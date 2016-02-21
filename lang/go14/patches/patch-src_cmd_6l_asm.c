$NetBSD: patch-src_cmd_6l_asm.c,v 1.2 2016/02/21 14:32:24 bsiegert Exp $

Support cgo on illumos.

--- src/cmd/6l/asm.c.orig	2015-09-23 04:37:36.000000000 +0000
+++ src/cmd/6l/asm.c
@@ -118,6 +118,8 @@ adddynrel(LSym *s, Reloc *r)
 		return;
 	
 	case 256 + R_X86_64_GOTPCREL:
+	case 256 + R_X86_64_GOTPCRELX:
+	case 256 + R_X86_64_REX_GOTPCRELX:
 		if(targ->type != SDYNIMPORT) {
 			// have symbol
 			if(r->off >= 2 && s->p[r->off-2] == 0x8b) {
@@ -209,12 +211,23 @@ adddynrel(LSym *s, Reloc *r)
 	
 	case R_ADDR:
 		if(s->type == STEXT && iself) {
-			// The code is asking for the address of an external
-			// function.  We provide it with the address of the
-			// correspondent GOT symbol.
-			addgotsym(targ);
-			r->sym = linklookup(ctxt, ".got", 0);
-			r->add += targ->got;
+			/*
+			 * On SunOS, all external references are dynamic.
+			 * Emit a PLT relocation at this site.
+			 */
+			if (HEADTYPE == Hsolaris) {
+				addpltsym(targ);
+				r->sym = linklookup(ctxt, ".plt", 0);
+				r->add = targ->plt;
+			} else {
+				// The code is asking for the address of an
+				// external function.  We provide it with the
+				// address of the correspondent GOT symbol.
+				addgotsym(targ);
+				r->sym = linklookup(ctxt, ".got", 0);
+				r->add += targ->got;
+			}
+
 			return;
 		}
 		if(s->type != SDATA)
@@ -539,28 +552,9 @@ adddynsym(Link *ctxt, LSym *s)
 	
 		/* reserved */
 		adduint8(ctxt, d, 0);
-	
-		/* section where symbol is defined */
-		if(s->type == SDYNIMPORT)
-			adduint16(ctxt, d, SHN_UNDEF);
-		else {
-			switch(s->type) {
-			default:
-			case STEXT:
-				t = 11;
-				break;
-			case SRODATA:
-				t = 12;
-				break;
-			case SDATA:
-				t = 13;
-				break;
-			case SBSS:
-				t = 14;
-				break;
-			}
-			adduint16(ctxt, d, t);
-		}
+
+		/* section where symbol is defined; see dodynsym(). */
+		adduint16(ctxt, d, SHN_UNDEF);
 	
 		/* value */
 		if(s->type == SDYNIMPORT)
