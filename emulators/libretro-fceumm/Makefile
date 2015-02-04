# $NetBSD: Makefile,v 1.1 2015/02/04 22:57:29 jmcneill Exp $

DISTNAME=	fceumm-libretro-20150204
PKGNAME=	libretro-fceumm-20150204
CATEGORIES=	emulators
MASTER_SITES=	http://ftp.NetBSD.org/pub/NetBSD/misc/jmcneill/retroarch/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libretro/libretro-fceumm
COMMENT=	Libretro core based on the FCEUmm emulator
LICENSE=	gnu-gpl-v2

WRKSRC=	${WRKDIR}/libretro-fceumm-master
MAKE_FILE=	Makefile.libretro
USE_TOOLS+=	gmake

CFLAGS+=	-DHAVE_ASPRINTF

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/fceumm_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/fceumm_libretro.so

.include "../../mk/bsd.pkg.mk"
