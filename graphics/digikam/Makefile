# $NetBSD: Makefile,v 1.137 2018/08/16 18:54:51 adam Exp $

DISTNAME=	digikam-4.13.0
PKGREVISION=	13
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_KDE:=digikam/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.digikam.org/
COMMENT=	Advanced digital photo management application (KDE4)
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2.1

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4
DEPENDS+=	qt4-sqlite3-[0-9]*:../../x11/qt4-sqlite3

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

REPLACE_PERL=	core/data/scripts/digitaglinktree/digitaglinktree
CMAKE_ARGS+=    -DMYSQLD_PATH:PATH=${BUILDLINK_PREFIX.mysql-server}/libexec
CMAKE_ARGS+=	-DENABLE_OPENCV3:BOOL=ON
USE_TOOLS+=	gawk msgfmt perl:run pkg-config

CXXFLAGS.NetBSD+=	-D_KERNTYPES

.include "options.mk"

post-patch:
	rm ${WRKSRC}/po/*/kipiplug* ${WRKSRC}/po/*/libkipi*

# jasper uses SIZE_MAX and friends in its headers.
CXXFLAGS+=	-D__STDC_LIMIT_MACROS

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../databases/mysql55-server/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/libkdcraw/buildlink3.mk"
.include "../../graphics/libkexiv2/buildlink3.mk"
.include "../../graphics/libkipi/buildlink3.mk"
.include "../../graphics/libksane/buildlink3.mk"
.include "../../graphics/libkface/buildlink3.mk"
.include "../../graphics/libpgf/buildlink3.mk"
.include "../../graphics/liblqr/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../misc/libkgeomap/buildlink3.mk"
.include "../../misc/libkvkontakte/buildlink3.mk"
.include "../../sysutils/libbaloo4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/libmediawiki/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
