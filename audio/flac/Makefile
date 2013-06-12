# $NetBSD: Makefile,v 1.47 2013/06/12 20:31:51 wiz Exp $

DISTNAME=	flac-1.3.0
CATEGORIES=	audio archivers
MASTER_SITES=	http://downloads.xiph.org/releases/flac/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xiph.org/flac/
COMMENT=	Free lossless audio codec
LICENSE=	modified-bsd AND gnu-gpl-v2 AND gnu-lgpl-v2.1

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		ac_cv_path_XMMS_CONFIG="no"
CONFIGURE_ENV+=		ac_cv_prog_DOXYGEN=""

PKGCONFIG_OVERRIDE+=	src/libFLAC++/flac++.pc.in src/libFLAC/flac.pc.in

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-i386)
BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm
.endif

.if !empty(MACHINE_PLATFORM:M*-*-powerpc)
.  if ${OPSYS} != "Darwin"
CONFIGURE_ARGS+=	--disable-asm-optimizations
CONFIGURE_ARGS+=	--disable-altivec
.  endif
.endif

.if !empty(MACHINE_PLATFORM:MDarwin-*-i386)
CONFIGURE_ARGS+=	--disable-asm-optimizations
.endif

.include "../../mk/compiler.mk"

# Version 1.1.2 of flac doesn't seem to build correctly with -O3 using
# the MIPSpro compiler.
# XXX: retry for 1.1.3
.if !empty(PKGSRC_COMPILER:Mmipspro)
BUILDLINK_TRANSFORM+=	rm:-O3
.endif

# SunPro does not support __inline
.if !empty(PKGSRC_COMPILER:Msunpro)
CFLAGS+=	-D__inline=inline
.endif

.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
