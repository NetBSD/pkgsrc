# $NetBSD: hacks.mk,v 1.3 2014/09/10 10:47:13 richard Exp $

.if !defined(M4_HACKS_MK)
M4_HACKS_MK=	defined

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

### [Mon Sep 24 09:00:13 EDT 2007 : dmcmahill]
###
### With gcc-3.3.5 on SunOS-5.9/sparc
### In file included from frexpl.c:19:
### frexp.c: In function `rpl_frexpl':
### frexp.c:167: error: insn does not satisfy its constraints:
### (insn 600 125 127 6 0 (set (reg:TF 10 %o2)
###         (mem/u/f:TF (lo_sum:SI (reg/f:SI 1 %g1 [138])
###                 (symbol_ref/u:SI ("*.LLC2"))) [0 S16 A64])) 74 {*movtf_insn_sp32} (nil)
###     (nil))
### frexp.c:167: internal compiler error: in reload_cse_simplify_operands, at reload1.c:8378
###
.if !empty(PKGSRC_COMPILER:Mgcc) && ${OPSYS} == "SunOS"
PKG_HACKS+=		optimisation
BUILDLINK_TRANSFORM+=	rm:-O[0-9]*
.endif

.endif	# M4_HACKS_MK
