# $NetBSD: Makefile,v 1.1 2015/02/13 21:21:03 snj Exp $

DISTNAME=	a0dd88872fc734cf4cc595df1cd1240fa213ac10
PKGNAME=	libretro-vba-next-20150105
CATEGORIES=	emulators games
MASTER_SITES=	https://github.com/libretro/vba-next/archive/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libretro/vbam-libretro
COMMENT=	Libretro core based on the VBA Next Game Boy Advance emulator

LICENSE=	gnu-gpl-v2

USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}/vba-next-${DISTNAME}
MAKE_FILE=	Makefile.libretro

INSTALLATION_DIRS=	lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/vba_next_libretro.so \
		${DESTDIR}${PREFIX}/lib/libretro/vba_next_libretro.so

.include "../../mk/bsd.pkg.mk"
