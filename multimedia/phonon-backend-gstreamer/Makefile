# $NetBSD: Makefile,v 1.34 2021/12/08 16:05:52 adam Exp $

DISTNAME=	phonon-backend-gstreamer-4.9.1

COMMENT=	Multimedia API for KDE and QT - GStreamer backend
PKGREVISION=	7

.include "Makefile.common"

DEPENDS+=	phonon-backend-gstreamer-shared>=${PKGVERSION_NOREV}{,nb*}:../../multimedia/phonon-backend-gstreamer-shared

.include "../../multimedia/phonon/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
