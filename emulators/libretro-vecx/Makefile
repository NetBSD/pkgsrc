# $NetBSD: Makefile,v 1.1 2018/08/11 16:09:55 nia Exp $

DISTNAME=	libretro-vecx-20180412
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_TAG=	25bfdd94900dcf5fd3d555ef686d857c0f087c2f

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/vecx/
COMMENT=	Libretro core for Vectrex emulation
LICENSE=	gnu-gpl-v3

EXTRACT_USING=	bsdtar
MAKE_FILE=	Makefile.libretro
USE_TOOLS+=	gmake

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/vecx_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/vecx_libretro.so

.include "../../mk/bsd.pkg.mk"
