# $NetBSD: Makefile,v 1.2 2009/04/06 13:13:04 markd Exp $

DISTNAME=	phonon-4.3.1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_KDE:=4.2.0/src/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://phonon.kde.org
COMMENT=	Multimedia API for KDE and QT

PKG_DESTDIR_SUPPORT=	user-destdir

# BUILD_MAKE_FLAGS+= VERBOSE=1

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4
DEPENDS+=	xine-xcb>=1.1.9:../../x11/xine-xcb

USE_DIRS+=	kde4-1.0
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_CMAKE=	yes
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	_build

PKGCONFIG_OVERRIDE+=	phonon.pc.cmake

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/
	${MKDIR} ${WRKSRC}/_build

.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
