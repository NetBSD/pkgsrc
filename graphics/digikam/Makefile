# $NetBSD: Makefile,v 1.82 2012/09/15 10:04:49 obache Exp $
#

DISTNAME=	digikam-2.5.0
PKGREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=digikam/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.digikam.org/
COMMENT=	Advanced digital photo management application (KDE4)
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2.1

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4
DEPENDS+=	qt4-sqlite3-[0-9]*:../../x11/qt4-sqlite3

PKG_DESTDIR_SUPPORT=	user-destdir
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

REPLACE_PERL=	core/utilities/scripts/digitaglinktree/digitaglinktree
CMAKE_ARGS+=    -DMYSQLD_PATH:PATH=${BUILDLINK_PREFIX.mysql-server}/libexec
USE_TOOLS+=	gawk msgfmt perl:run pkg-config

.include "options.mk"

post-patch:
	rm ${WRKSRC}/po/*/libkgeomap.po ${WRKSRC}/po/*/kipiplug*

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../databases/mysql51-server/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libkdcraw/buildlink3.mk"
.include "../../graphics/libkexiv2/buildlink3.mk"
.include "../../graphics/libkipi/buildlink3.mk"
.include "../../graphics/libksane/buildlink3.mk"
.include "../../graphics/libkface/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/liblqr/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../misc/libkgeomap/buildlink3.mk"
.include "../../misc/libkvkontakte/buildlink3.mk"
.include "../../multimedia/kdemultimedia4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/libmediawiki/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
