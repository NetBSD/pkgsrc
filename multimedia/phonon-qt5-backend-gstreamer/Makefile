# $NetBSD: Makefile,v 1.4 2016/04/26 09:04:23 markd Exp $

DISTNAME=	phonon-backend-gstreamer-4.9.0
PKGNAME=	${DISTNAME:S/-/-qt5-/}

COMMENT=	Multimedia API for KF5 - GStreamer backend

.include "../../multimedia/phonon-backend-gstreamer/Makefile.common"

DEPENDS+=	phonon-backend-gstreamer-shared-4.9.0:../../multimedia/phonon-backend-gstreamer-shared

CMAKE_ARGS+=	-DPHONON_BUILD_PHONON4QT5=ON

.include "../../multimedia/phonon-qt5/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
