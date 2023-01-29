# $NetBSD: Makefile,v 1.35 2023/01/29 21:17:21 ryoon Exp $

DISTNAME=	phonon-backend-gstreamer-4.9.1

COMMENT=	Multimedia API for KDE and QT - GStreamer backend
PKGREVISION=	8

.include "Makefile.common"

DEPENDS+=	phonon-backend-gstreamer-shared>=${PKGVERSION_NOREV}{,nb*}:../../multimedia/phonon-backend-gstreamer-shared

.include "../../multimedia/phonon/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
