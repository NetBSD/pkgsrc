# $NetBSD: Makefile,v 1.3 2018/09/06 07:50:20 nia Exp $

PKGNAME=	libretro-database-${RETROARCH_VERSION}
DISTNAME=	retroarch-assets-${RETROARCH_VERSION}
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

.include "../../emulators/retroarch/version.mk"
.include "../../mk/bsd.pkg.mk"
