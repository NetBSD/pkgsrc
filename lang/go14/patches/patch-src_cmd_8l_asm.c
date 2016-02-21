$NetBSD: patch-src_cmd_8l_asm.c,v 1.2 2016/02/21 14:32:24 bsiegert Exp $

Support cgo on illumos.

--- src/cmd/8l/asm.c.orig	2015-09-23 04:37:36.000000000 +0000
+++ src/cmd/8l/asm.c
@@ -115,6 +115,7 @@ adddynrel(LSym *s, Reloc *r)
 		return;		
 	
 	case 256 + R_386_GOT32:
+	case 256 + R_386_GOT32X:
 		if(targ->type != SDYNIMPORT) {
 			// have symbol
 			if(r->off >= 2 && s->p[r->off-2] == 0x8b) {
@@ -508,27 +509,8 @@ adddynsym(Link *ctxt, LSym *s)
 		adduint8(ctxt, d, t);
 		adduint8(ctxt, d, 0);
 	
-		/* shndx */
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
+		/* shndx; see dodynsym(). */
+		adduint16(ctxt, d, SHN_UNDEF);
 	} else if(HEADTYPE == Hdarwin) {
 		diag("adddynsym: missed symbol %s (%s)", s->name, s->extname);
 	} else if(HEADTYPE == Hwindows) {
