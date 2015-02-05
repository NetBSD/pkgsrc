# $NetBSD: Makefile,v 1.1 2015/02/05 02:23:37 jmcneill Exp $

DISTNAME=	catsfc-libretro-20150204
PKGNAME=	libretro-catsfc-20150204
CATEGORIES=	emulators
MASTER_SITES=	http://ftp.NetBSD.org/pub/NetBSD/misc/jmcneill/retroarch/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libretro/CATSFC-libretro
COMMENT=	Libretro core based on the CATSFC Super Nintendo emulator

WRKSRC=		${WRKDIR}/CATSFC-libretro-master
USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/catsfc_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/catsfc_libretro.so

.include "../../mk/bsd.pkg.mk"
