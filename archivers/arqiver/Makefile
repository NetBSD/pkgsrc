# $NetBSD: Makefile,v 1.6 2020/04/12 08:28:17 adam Exp $

VERSION=	0.4.0
DISTNAME=	Arqiver-V${VERSION}
PKGNAME=	arqiver-${VERSION}
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=tsujan/}
GITHUB_TAG=	V${PKGVERSION_NOREV}

MAINTAINER=	voidpin@protonmail.com
HOMEPAGE=	https://github.com/tsujan/Arqiver/
COMMENT=	Simple Qt5 archive manager
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/Arqiver-${VERSION}
USE_LANGUAGES=	c++
USE_TOOLS+=	pkg-config bsdtar:run gzip:run 7za:run

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

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

do-configure:
	cd ${WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} \
	${QTDIR}/bin/qmake -o Makefile PREFIX=${PREFIX}

# Either needs misc/xdg-utils for xdg-open or devel/glib2 for gio.
# Upstream prefers glib2, but xdg-utils is a lot smaller, so use
# that for now.
DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
