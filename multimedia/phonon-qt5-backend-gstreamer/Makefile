# $NetBSD: Makefile,v 1.25 2020/06/02 08:24:28 adam Exp $

DISTNAME=	phonon-backend-gstreamer-4.9.1
PKGNAME=	${DISTNAME:S/-/-qt5-/}
PKGREVISION=	6

COMMENT=	Multimedia API for KF5 - GStreamer backend

.include "../../multimedia/phonon-backend-gstreamer/Makefile.common"

BUILD_DEPENDS+=	extra-cmake-modules>=5.19.0:../../devel/extra-cmake-modules
DEPENDS+=	phonon-backend-gstreamer-shared-${PKGVERSION_NOREV}{,nb*}:../../multimedia/phonon-backend-gstreamer-shared

CMAKE_ARGS+=	-DPHONON_BUILD_PHONON4QT5=ON

.include "../../multimedia/phonon-qt5/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
