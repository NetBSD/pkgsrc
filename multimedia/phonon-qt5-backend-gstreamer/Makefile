# $NetBSD: Makefile,v 1.2 2016/03/05 11:29:01 jperkin Exp $

DISTNAME=	phonon-backend-gstreamer-4.8.2
PKGNAME=	${DISTNAME:S/-/-qt5-/}
PKGREVISION=	1

COMMENT=	Multimedia API for KF5 - GStreamer backend

.include "../../multimedia/phonon-backend-gstreamer/Makefile.common"

DEPENDS+=	phonon-backend-gstreamer-shared-4.8.2:../../multimedia/phonon-backend-gstreamer-shared

CMAKE_ARGS+=	-DPHONON_BUILD_PHONON4QT5=ON

.include "../../multimedia/phonon-qt5/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
