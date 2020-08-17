# $NetBSD: Makefile,v 1.31 2020/08/17 20:19:41 leot Exp $

DISTNAME=	phonon-backend-gstreamer-4.9.1

COMMENT=	Multimedia API for KDE and QT - GStreamer backend
PKGREVISION=	4

.include "Makefile.common"

DEPENDS+=	phonon-backend-gstreamer-shared-${PKGVERSION_NOREV}{,nb*}:../../multimedia/phonon-backend-gstreamer-shared

.include "../../multimedia/phonon/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
