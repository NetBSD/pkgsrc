# $NetBSD: Makefile,v 1.2 2018/08/07 16:41:48 nia Exp $

VERSION=	1.7.3
PKGNAME=	libretro-database-${VERSION}
DISTNAME=	retroarch-assets-${VERSION}
CATEGORIES=	emulators
MASTER_SITES=	-http://buildbot.libretro.com/stable/${PKGVERSION_NOREV}/windows-msvc2010/x86_64/RetroArch.7z
EXTRACT_SUFX=	.7z

HOMEPAGE=	https://www.libretro.com/
MAINTAINER=	nia@NetBSD.org
COMMENT=	ROM scanning data provided by the libretro project
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	share/libretro/database/rdb
INSTALLATION_DIRS+=	share/libretro/database/cursors

do-install:
	${INSTALL_DATA} ${WRKSRC}/database/rdb/*.rdb \
	    ${DESTDIR}${PREFIX}/share/libretro/database/rdb
	${INSTALL_DATA} ${WRKSRC}/database/cursors/*.dbc \
	    ${DESTDIR}${PREFIX}/share/libretro/database/cursors

.include "../../mk/bsd.pkg.mk"
