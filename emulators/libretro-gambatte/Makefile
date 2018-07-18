# $NetBSD: Makefile,v 1.2 2018/07/18 00:06:14 joerg Exp $

DISTNAME=	gambatte-libretro-20150204
PKGNAME=	libretro-gambatte-20150204
CATEGORIES=	emulators
MASTER_SITES=	http://ftp.NetBSD.org/pub/NetBSD/misc/jmcneill/retroarch/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libretro/gambatte-libretro
COMMENT=	Libretro core based on the Gambatte Game Boy Color emulator
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/gambatte-libretro-master/libgambatte
USE_LANGUAGES=	c c++03
MAKE_FILE=	Makefile.libretro
USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/gambatte_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/gambatte_libretro.so

.include "../../mk/bsd.pkg.mk"
