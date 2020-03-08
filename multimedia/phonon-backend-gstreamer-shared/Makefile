# $NetBSD: Makefile,v 1.4 2020/03/08 16:50:46 wiz Exp $

DISTNAME=	phonon-backend-gstreamer-4.9.1
PKGNAME=	${DISTNAME:S/-4/-shared-4/}
PKGREVISION=	1

COMMENT=	Multimedia API for KF5 - GStreamer backend shared files

.include "../../multimedia/phonon-backend-gstreamer/Makefile.common"

do-configure:

do-build:

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/gstreamer/icons/hisc-apps-phonon-gstreamer.svgz \
		 ${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps/phonon-gstreamer.svgz
.for i in 128 64 48 22 16 
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps
	${INSTALL_DATA} ${WRKSRC}/gstreamer/icons/hi${i}-apps-phonon-gstreamer.png \
		 ${DESTDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/phonon-gstreamer.png
.endfor

.include "../../mk/bsd.pkg.mk"
