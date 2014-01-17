# $NetBSD: hacks.mk,v 1.3 2014/01/17 10:03:23 pho Exp $

.if !defined(OCAML_HACKS_MK)
OCAML_HACKS_MK=	defined

.include "../../mk/compiler.mk"

### [Fri Jan 17 18:06:18 JST 2014 : pho]
### The linker comes with Darwin 9 does not recognize the option
### "-no_compact_unwind" since compact unwind information is only
### introduced (and made default) as of Darwin 10.  Note that this
### can't be worked around with transformation
### "rm:-Wl,-no_compact_unwind" because the linker option is baked
### into utils/config.ml and will later be used by the OCaml compiler
### itself.
###
.if !empty(MACHINE_PLATFORM:MDarwin-9.*)
PKG_HACKS+=	no_compact_unwind
SUBST_CLASSES+=	no_compact_unwind
SUBST_MESSAGE.no_compact_unwind= Removing -no_compact_unwind from linker options
SUBST_FILES.no_compact_unwind=	configure
SUBST_SED.no_compact_unwind=	-e 's/-Wl,-no_compact_unwind//g'
SUBST_STAGE.no_compact_unwind=	pre-configure
.endif

### [ Wed Oct  7 9:16:42 GMT 2009 : dmcmahill ]
### On NetBSD/i386, gcc optimisation, at least for version 4.4.1 (lang/gcc44),
### produces a binary which segfaults.  The binary is used during part of the
### build process.
###
.if !empty(MACHINE_PLATFORM:MNetBSD-*-i386)
.  if !empty(CC_VERSION:Mgcc-4.4.*)
PKG_HACKS+=		optimisation
BUILDLINK_TRANSFORM+=	rename:-O[0-9]*:-O
.  endif
.endif

.endif  # OCAML_HACKS_MK
