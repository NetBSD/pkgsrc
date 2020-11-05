# $NetBSD: Makefile,v 1.9 2020/11/05 09:09:00 ryoon Exp $

DISTNAME=	xpdf-4.02
PKGREVISION=	8
CATEGORIES=	print
MASTER_SITES=	https://xpdfreader-dl.s3.amazonaws.com/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.xpdfreader.com/
COMMENT=	Display tool for PDF files (Qt version)
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

TOOL_DEPENDS+=	icoutils-[0-9]*:../../graphics/icoutils

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/icons/hicolor/scalable/apps
INSTALLATION_DIRS+=	share/icons/hicolor/256x256/apps

post-build:
	cd ${WRKSRC} && ${PREFIX}/bin/icotool -w 256 -h 256 -x -o xpdf-icon.png xpdf-qt/xpdf-icon.ico

post-install:
	# Avoid conflicting with poppler-utils
	${RM} ${DESTDIR}${PREFIX}/bin/pdf*
	${RM} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/pdf*
	${INSTALL_DATA} ${FILESDIR}/xpdf.desktop ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/xpdf-qt/xpdf-icon.svg \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps/xpdf.svg
	${INSTALL_DATA} ${WRKSRC}/xpdf-icon.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/256x256/apps/xpdf.png

.include "options.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../print/libpaper/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
