# $NetBSD: Makefile,v 1.3 2018/08/11 20:26:12 nia Exp $

DISTNAME=	libretro-nestopia-1.49
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	nestopia

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/nestopia_ue/
COMMENT=	Libretro core based on the Nestopia UE emulator
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	bsdtar
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}
BUILD_DIRS=	libretro
USE_LANGUAGES=	c c++03
USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro
INSTALLATION_DIRS+=	share/libretro-nestopia

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"
CFLAGS+=	-DPREFIX=\"${PREFIX}\"

do-install:
	${INSTALL_LIB} ${WRKSRC}/libretro/nestopia_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/nestopia_libretro.so
	${INSTALL_DATA} ${WRKSRC}/NstDatabase.xml \
	    ${DESTDIR}${PREFIX}/share/libretro-nestopia

.include "../../mk/bsd.pkg.mk"
