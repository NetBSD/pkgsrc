# $NetBSD: Makefile,v 1.3 2020/05/26 09:45:17 nia Exp $

DISTNAME=	libretro-vecx-20180412
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_TAG=	25bfdd94900dcf5fd3d555ef686d857c0f087c2f

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/vecx/
COMMENT=	Libretro core for Vectrex emulation
LICENSE=	gnu-gpl-v3

MAKE_FILE=	Makefile.libretro
USE_TOOLS+=	gmake

OPSYSVARS+=	SOEXT
SOEXT.Darwin=	dylib
SOEXT.*=	so
PLIST_SUBST+=	SOEXT=${SOEXT}

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=./link.T

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/vecx_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/vecx_libretro.so

.include "../../mk/bsd.pkg.mk"
