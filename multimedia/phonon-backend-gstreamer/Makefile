# $NetBSD: Makefile,v 1.23 2016/03/01 09:21:01 markd Exp $

DISTNAME=	phonon-backend-gstreamer-4.8.2
PKGREVISION=	1

COMMENT=	Multimedia API for KDE and QT - GStreamer backend

.include "Makefile.common"

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4
DEPENDS+=	phonon-backend-gstreamer-shared-4.8.2:../../multimedia/phonon-backend-gstreamer-shared

.include "../../multimedia/phonon/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
