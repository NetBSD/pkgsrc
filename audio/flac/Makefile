# $NetBSD: Makefile,v 1.63 2025/02/13 10:59:45 triaxx Exp $

DISTNAME=	flac-1.5.0
PKGREVISION=	1
CATEGORIES=	audio archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=xiph/}
GITHUB_PROJECT=	flac
GITHUB_RELEASE=	${PKGVERSION_NOREV}
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
CONFIGURE_ENV+=		ac_cv_prog_PANDOC=
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
