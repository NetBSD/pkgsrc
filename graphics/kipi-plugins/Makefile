# $NetBSD: Makefile,v 1.101 2014/05/05 00:47:58 ryoon Exp $
#

PKGNAME=	kipi-plugins-3.5.0
DISTNAME=	digikam-3.5.0
PKGREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_KDE:=digikam/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.digikam.org/
COMMENT=	Common plugin structure for KDE4 programs
#LICENSE=	gnu-gpl-v2 AND Adobe DNG SDK license

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4
DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		msgfmt pkg-config bison

WRKSRC=			${WRKDIR}/${DISTNAME}/extra/kipi-plugins

post-patch:
	${ECHO} "FIND_PACKAGE(Msgfmt REQUIRED)" >> ${WRKSRC}/CMakeLists.txt
	${ECHO} "FIND_PACKAGE(Gettext REQUIRED)" >> ${WRKSRC}/CMakeLists.txt
	${ECHO} "ADD_SUBDIRECTORY(po)" >> ${WRKSRC}/CMakeLists.txt
	ln -s ../../po ${WRKSRC}/po
	rm ${WRKSRC}/po/*/digikam.po ${WRKSRC}/po/*/libkgeomap.po ${WRKSRC}/po/*/libkipi.po

SUBST_CLASSES+=		xdg
SUBST_SED.xdg=		-e "s,/usr/bin/env xdg-open,${PREFIX}/bin/xdg-open,"
SUBST_FILES.xdg=	expoblending/plugin/expoblending.desktop panorama/plugin/panoramagui.desktop
SUBST_STAGE.xdg=	pre-build
SUBST_MESSAGE.xdg=	Fixing path in desktop file.

.include "../../meta-pkgs/kde4/kde4.mk"
# for IpodExport
.include "../../audio/libgpod/buildlink3.mk"
.include "../../graphics/libkdcraw/buildlink3.mk"
.include "../../graphics/libkexiv2/buildlink3.mk"
.include "../../graphics/libkipi/buildlink3.mk"
.include "../../graphics/libksane/buildlink3.mk"
.include "../../misc/libkgeomap/buildlink3.mk"
.include "../../www/libmediawiki/buildlink3.mk"
.include "../../misc/libkvkontakte/buildlink3.mk"
# for RemoveRedEyes
.include "../../graphics/opencv/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
# for Calendar
.include "../../misc/kdepimlibs4/buildlink3.mk"
# for Shwup
.include "../../security/qca2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
