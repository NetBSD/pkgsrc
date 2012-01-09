# $NetBSD: Makefile,v 1.64 2012/01/09 02:54:26 obache Exp $
#

DISTNAME=	kipi-plugins-1.6.0
PKGREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kipi/kipi-plugins/1.6.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kipi-plugins.org/drupal/
COMMENT=	Common plugin structure for KDE4 programs
#LICENSE=	gnu-gpl-v2 AND Adobe DNG SDK license

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4
DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		msgfmt pkg-config

SUBST_CLASSES+=		xdg
SUBST_SED.xdg=		-e "s,/usr/bin/env xdg-open,${PREFIX}/bin/xdg-open,"
SUBST_FILES.xdg=	expoblending/expoblending.desktop
SUBST_STAGE.xdg=	pre-build
SUBST_MESSAGE.xdg=	Fixing path in desktop file.

BUILDLINK_API_DEPENDS.kdelibs+= kdelibs4>=4.4.0
.include "../../meta-pkgs/kde4/kde4.mk"
# for IpodExport
.include "../../audio/libgpod/buildlink3.mk"
.include "../../graphics/kdegraphics4/buildlink3.mk"
# for RemoveRedEyes
.include "../../graphics/opencv/buildlink3.mk"
# for Calendar
.include "../../misc/kdepimlibs4/buildlink3.mk"
# for Shwup
.include "../../security/qca2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
