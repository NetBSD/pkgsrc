# $NetBSD: Makefile,v 1.30 2020/03/09 23:21:19 tnn Exp $

DISTNAME=	phonon-backend-gstreamer-4.9.1

COMMENT=	Multimedia API for KDE and QT - GStreamer backend
PKGREVISION=	3

.include "Makefile.common"

DEPENDS+=	phonon-backend-gstreamer-shared-${PKGVERSION_NOREV}{,nb*}:../../multimedia/phonon-backend-gstreamer-shared

.include "../../multimedia/phonon/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
