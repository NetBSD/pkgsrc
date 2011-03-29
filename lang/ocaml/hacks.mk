# $NetBSD: hacks.mk,v 1.2 2011/03/29 13:45:02 adam Exp $

.if !defined(OCAML_HACKS_MK)
OCAML_HACKS_MK=	defined

.include "../../mk/compiler.mk"

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
