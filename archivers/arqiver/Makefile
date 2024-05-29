# $NetBSD: Makefile,v 1.34 2024/05/29 16:31:16 adam Exp $

DISTNAME=	Arqiver-0.12.0
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=tsujan/}
GITHUB_TAG=	V${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/tsujan/Arqiver/
COMMENT=	Simple Qt5/Qt6 archive manager
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config bsdtar:run gzip:run 7za:run

CMAKE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing paths.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	backends.cpp
SUBST_SED.prefix=	-e 's,"tar","${TOOLS_PATH.bsdtar}",g'
SUBST_SED.prefix+=	-e 's,"bsdtar","${TOOLS_PATH.bsdtar}",g'
SUBST_SED.prefix+=	-e 's,"gzip","${TOOLS_PATH.gzip}",g'
SUBST_SED.prefix+=	-e 's,"7z","${TOOLS_PATH.7za}",g'
# (Can't include closing double-quotes below, as there are varying
# character sequences following the command references.)
SUBST_SED.prefix+=	-e 's,"xdg-open,"${PREFIX}/bin/xdg-open,g'

.include "options.mk"

# Either needs misc/xdg-utils for xdg-open or devel/glib2 for gio.
# Upstream prefers glib2, but xdg-utils is a lot smaller, so use
# that for now.
DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
