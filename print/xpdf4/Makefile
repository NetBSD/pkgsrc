# $NetBSD: Makefile,v 1.35 2024/05/16 06:15:29 wiz Exp $

DISTNAME=	xpdf-4.05
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	https://dl.xpdfreader.com/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.xpdfreader.com/
COMMENT=	Display tool for PDF files (Qt version)
LICENSE=	gnu-gpl-v2

DEPENDS+=	urw-fonts-[0-9]*:../../fonts/urw-fonts

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

TOOL_DEPENDS+=	icoutils-[0-9]*:../../graphics/icoutils

# don't accidentally find qt6
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Qt6Widgets=TRUE

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/icons/hicolor/scalable/apps
INSTALLATION_DIRS+=	share/icons/hicolor/256x256/apps

EGDIR=			${PREFIX}/share/examples/xpdf
CONF_FILES=		${EGDIR}/xpdfrc ${PKG_SYSCONFDIR}/xpdfrc
INSTALLATION_DIRS+=	${EGDIR}

SUBST_CLASSES+=		paths
SUBST_FILES.paths+=	doc/sample-xpdfrc xpdf/GlobalParams.cc
SUBST_VARS.paths=	PREFIX
SUBST_STAGE.paths=	pre-configure

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
	${INSTALL_DATA} ${WRKSRC}/doc/sample-xpdfrc \
	    ${DESTDIR}${EGDIR}/xpdfrc

.include "options.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../print/libpaper/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
