# $NetBSD: Makefile,v 1.28 2012/10/01 13:02:24 ryoon Exp $
#

DISTNAME=	fotoxx-12.10
CATEGORIES=	graphics
MASTER_SITES=	http://www.kornelix.com/uploads/1/3/0/3/13035936/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kornelix.com/fotoxx.html
COMMENT=	Program for editing image files from a digital camera
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils
DEPENDS+=	p5-Image-ExifTool-[0-9]*:../../graphics/p5-Image-ExifTool
DEPENDS+=	dcraw-[0-9]*:../../graphics/dcraw
DEPENDS+=	gimp-ufraw-[0-9]*:../../graphics/gimp-ufraw

USE_LANGUAGES=	c++
USE_TOOLS+=	pkg-config
TOOLS_NOOP+=	xdg-desktop-menu

BUILD_TARGET=	fotoxx
INSTALL_TARGET=	install

.include "../../mk/bsd.prefs.mk"

.if exists(/usr/include/execinfo.h)
CXXFLAGS+=	-DHAVE_EXECINFO_H
.  if (${OPSYS} == "NetBSD")
LDFLAGS+=	-lexecinfo
.  endif
.endif

.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
