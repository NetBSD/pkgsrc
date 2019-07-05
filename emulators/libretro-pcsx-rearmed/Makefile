# $NetBSD: Makefile,v 1.8 2019/07/05 08:38:36 nia Exp $

DISTNAME=	libretro-pcsx-rearmed-0.22
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=notaz/}
GITHUB_PROJECT=	pcsx_rearmed
GITHUB_TAG=	r22

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://notaz.gp2x.de/pcsx_rearmed.php
COMMENT=	Libretro core based on the PCSX ReARMed emulator
LICENSE=	gnu-gpl-v2

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

do-install:
	${INSTALL_LIB} ${WRKSRC}/pcsx_rearmed_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/pcsx_rearmed_libretro.so

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
