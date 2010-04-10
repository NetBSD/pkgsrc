# $NetBSD: Makefile,v 1.8 2010/04/10 00:18:13 markd Exp $

DISTNAME=	phonon-4.4.0
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_KDE:=phonon/4.4.0/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://phonon.kde.org
COMMENT=	Multimedia API for KDE and QT
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

# BUILD_MAKE_FLAGS+= VERBOSE=1

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4
DEPENDS+=	xine-xcb>=1.1.9:../../x11/xine-xcb

WRKSRC=		${WRKDIR}/phonon-4.4
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_CMAKE=	yes
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	_build
CMAKE_ARGS+=	-DWITH_PulseAudio:BOOL=OFF

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
