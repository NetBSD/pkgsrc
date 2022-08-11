# $NetBSD: Makefile,v 1.69 2022/08/11 05:08:40 gutteridge Exp $
#

DISTNAME=	fotoxx-16.02.1
PKGREVISION=	14
CATEGORIES=	graphics
MASTER_SITES=	http://www.kornelix.com/downloads/tarballs/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kornelix.com/fotoxx/fotoxx.html
COMMENT=	Program for editing image files from a digital camera
LICENSE=	gnu-gpl-v3

BUILD_DEFS+=	PKG_SYSCONFBASE

PKG_SYSCONFSUBDIR=	xdg/menus

# XXX work around misc/xdg-utils being completely broken
XDG_CONFIG_DIRS=	"${DESTDIR}${PKG_SYSCONFBASE}/xdg"
MAKE_ENV+=		XDG_CONFIG_DIRS="${XDG_CONFIG_DIRS}"
MAKE_ENV+=		XDG_DATA_DIRS="${DESTDIR}${PREFIX}/share"

OWN_DIRS+=	${PREFIX}/share/desktop-directories

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils
DEPENDS+=	p5-Image-ExifTool-[0-9]*:../../graphics/p5-Image-ExifTool
DEPENDS+=	dcraw-[0-9]*:../../graphics/dcraw
DEPENDS+=	gimp-ufraw-[0-9]*:../../graphics/gimp-ufraw

USE_LANGUAGES=	c++
USE_TOOLS+=	pkg-config

BUILD_TARGET=	fotoxx
INSTALL_TARGET=	install

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		desktop
SUBST_SED.fix-paths=		-e 's,=/usr,=${PREFIX},g'

# XXX work around misc/xdg-utils being completely broken
pre-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PKG_SYSCONFDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/desktop-directories

.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
