# $NetBSD: options.mk,v 1.2 2005/12/01 20:18:29 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pgp2
PKG_SUPPORTED_OPTIONS=	rsaref

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "m68k"
PKG_SUPPORTED_OPTIONS+=	m68060-optimized
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mrsaref)
PKGNAME=	pgp-2.6.3a
.include "../../security/rsaref/buildlink3.mk"
RSAINC=		-I${BUILDLINK_PREFIX.rsaref}/include
RSALIBS=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.rsaref}/lib -L${BUILDLINK_PREFIX.rsaref}/lib -lrsaref
RSAOBJS=	rsaglue2.o
CFLAGS+=	-DUSA
.else
PKGNAME=	pgp-2.6.3ia
RSAINC=
RSALIBS=
RSAOBJS=	rsaglue1.o
.endif
FIX_RPATH+=	RSALIBS

.if ${MACHINE_ARCH} == "m68k"
.if !empty(PKG_OPTIONS:Mm68060-optimized)
OBJS_EXT=
ASMFLAG=	-m68060 -DPORTABLE -DMPORTABLE
.else
OBJS_EXT=	mc68020.o
ASMFLAG=
.endif
.endif
