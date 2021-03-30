# $NetBSD: Makefile,v 1.32 2021/03/30 09:05:14 markd Exp $

DISTNAME=	phonon-backend-gstreamer-4.9.1

COMMENT=	Multimedia API for KDE and QT - GStreamer backend
PKGREVISION=	5

.include "Makefile.common"

DEPENDS+=	phonon-backend-gstreamer-shared>=${PKGVERSION_NOREV}{,nb*}:../../multimedia/phonon-backend-gstreamer-shared

.include "../../multimedia/phonon/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
