# $NetBSD: Makefile,v 1.37 2023/11/12 13:23:02 wiz Exp $

DISTNAME=	phonon-backend-gstreamer-4.9.1

COMMENT=	Multimedia API for KDE and QT - GStreamer backend
PKGREVISION=	10

.include "Makefile.common"

DEPENDS+=	phonon-backend-gstreamer-shared>=${PKGVERSION_NOREV}{,nb*}:../../multimedia/phonon-backend-gstreamer-shared

.include "../../multimedia/phonon/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
