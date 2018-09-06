# $NetBSD: Makefile,v 1.4 2018/09/06 09:33:38 nia Exp $

DISTNAME=	libretro-database-20180904
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	libretro-database
GITHUB_TAG=	aa0f09390e45da02c84732812103abb9cd63ee65

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.libretro.com/
COMMENT=	ROM scanning data provided by the libretro project
LICENSE=	gnu-gpl-v3

EXTRACT_USING=	bsdtar
USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	share/libretro/database/rdb
INSTALLATION_DIRS+=	share/libretro/database/cursors

do-install:
	${INSTALL_DATA} ${WRKSRC}/rdb/*.rdb \
	    ${DESTDIR}${PREFIX}/share/libretro/database/rdb
	${INSTALL_DATA} ${WRKSRC}/cursors/*.dbc \
	    ${DESTDIR}${PREFIX}/share/libretro/database/cursors

.include "../../mk/bsd.pkg.mk"
