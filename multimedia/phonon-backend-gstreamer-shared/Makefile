# $NetBSD: Makefile,v 1.5 2021/03/30 09:03:32 markd Exp $

DISTNAME=	phonon-backend-gstreamer-4.10.0
PKGNAME=	${DISTNAME:S/-4/-shared-4/}
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_KDE:=phonon/phonon-backend-gstreamer/4.10.0/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	markd@NetBSD.org
COMMENT=	Multimedia API for KF5 - GStreamer backend shared files
HOMEPAGE=	https://phonon.kde.org/
LICENSE=	gnu-lgpl-v2.1

DISTINFO_FILE=	${.CURDIR}/../../multimedia/phonon-qt5-backend-gstreamer/distinfo

do-configure:

do-build:

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/gstreamer/icons/sc-apps-phonon-gstreamer.svg \
		 ${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps/phonon-gstreamer.svg
.for i in 128 64 48 22 16 
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps
	${INSTALL_DATA} ${WRKSRC}/gstreamer/icons/${i}-apps-phonon-gstreamer.png \
		 ${DESTDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/phonon-gstreamer.png
.endfor

.include "../../mk/bsd.pkg.mk"
