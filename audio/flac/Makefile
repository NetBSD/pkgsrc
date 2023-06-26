# $NetBSD: Makefile,v 1.61 2023/06/26 11:35:49 adam Exp $

DISTNAME=	flac-1.4.3
CATEGORIES=	audio archivers
MASTER_SITES=	http://downloads.xiph.org/releases/flac/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xiph.org/flac/
COMMENT=	Free lossless audio codec
LICENSE=	modified-bsd AND gnu-gpl-v2 AND gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-doxygen-docs
PKGCONFIG_OVERRIDE+=	src/libFLAC++/flac++.pc.in
PKGCONFIG_OVERRIDE+=	src/libFLAC/flac.pc.in
TEST_TARGET=		check

BUILD_DEFS+=		PKGSRC_MKPIE

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
.  if ${PKGSRC_MKPIE:tl} == "yes" || ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--disable-asm-optimizations
.  endif
.endif

.if ${MACHINE_PLATFORM:M*-*-powerpc}
.  if ${OPSYS} != "Darwin"
CONFIGURE_ARGS+=	--disable-asm-optimizations
CONFIGURE_ARGS+=	--disable-altivec
.  endif
.endif

.include "../../mk/compiler.mk"

# SunPro does not support __inline
.if !empty(PKGSRC_COMPILER:Msunpro)
CFLAGS+=	-D__inline=inline
.endif

# With -fgnu89-inline option duplicate symbols arise.
.if !empty(PKGSRC_COMPILER:Mclang)
BUILDLINK_TRANSFORM+=	rm:-fgnu89-inline
.endif

.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
