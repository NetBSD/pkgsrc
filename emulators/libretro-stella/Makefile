# $NetBSD: Makefile,v 1.1 2015/02/05 22:38:59 jmcneill Exp $

DISTNAME=	stella-libretro-20150205
PKGNAME=	libretro-stella-20150205
CATEGORIES=	emulators
MASTER_SITES=	http://ftp.NetBSD.org/pub/NetBSD/misc/jmcneill/retroarch/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libretro/stella-libretro
COMMENT=	Libretro core based on the Stella Atari 2600 (VCS) emulator
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/stella-libretro-master
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/stella_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/stella_libretro.so

.include "../../mk/bsd.pkg.mk"
