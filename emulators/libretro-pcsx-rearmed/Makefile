# $NetBSD: Makefile,v 1.4 2015/02/10 17:51:37 jmcneill Exp $

DISTNAME=	r22
DIST_SUBDIR=	pcsx_rearmed
PKGNAME=	libretro-pcsx-rearmed-0.22
CATEGORIES=	emulators
MASTER_SITES=	https://github.com/notaz/pcsx_rearmed/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://notaz.gp2x.de/pcsx_rearmed.php
COMMENT=	Libretro core based on the PCSX ReARMed emulator
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/pcsx_rearmed-${DISTNAME}
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
MAKE_FILE=	Makefile.libretro

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

BUILDLINK_TRANSFORM+=	rm:-ldl

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_ARCH:M*arm*hf)
PCSX_REARMED_PLATFORM=	${MACHINE_ARCH}-hardfloat
.else
PCSX_REARMED_PLATFORM=	unix
.endif

MAKE_ENV+=	platform="${PCSX_REARMED_PLATFORM}"

.if !empty(MACHINE_ARCH:M*arm*)
# only ARM-specific options for now, and options framework
#insists on having at least one option, so only pull it in for ARM
.include "options.mk"
.endif

do-install:
	${INSTALL_LIB} ${WRKSRC}/pcsx_rearmed_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/pcsx_rearmed_libretro.so

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
