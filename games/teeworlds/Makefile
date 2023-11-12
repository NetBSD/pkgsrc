# $NetBSD: Makefile,v 1.30 2023/11/12 13:21:44 wiz Exp $

DISTNAME=	teeworlds-0.7.5-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	11
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=teeworlds/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.teeworlds.com/
COMMENT=	Fast-paced retro multiplayer shooter
LICENSE=	zlib AND 2-clause-bsd AND modified-bsd AND cc-by-sa-v3.0

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-Wno-dev

TOOL_DEPENDS+=	icoutils-[0-9]*:../../graphics/icoutils

LDFLAGS.SunOS+=	-lsocket -lnsl

# error: 'for' loop initial declarations are only allowed in C99 mode
FORCE_C_STD=		gnu99

# Fails with C++14 default language
FORCE_CXX_STD=		gnu++03

INSTALLATION_DIRS+=	share/appdata
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps

PYTHON_FOR_BUILD_ONLY=	tool

post-build:
	${PREFIX}/bin/icotool -x -i 1 ${WRKSRC}/other/icons/teeworlds.ico -o ${WRKDIR}/teeworlds.png

post-install:
	${INSTALL_DATA} ${WRKSRC}/other/teeworlds.desktop ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/other/teeworlds.appdata.xml ${DESTDIR}${PREFIX}/share/appdata
	${INSTALL_DATA} ${WRKDIR}/teeworlds.png ${DESTDIR}${PREFIX}/share/pixmaps

.include "../../audio/wavpack/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
