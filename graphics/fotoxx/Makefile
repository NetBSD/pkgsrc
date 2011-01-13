# $NetBSD: Makefile,v 1.10 2011/01/13 13:38:01 wiz Exp $
#

DISTNAME=	fotoxx-10.8.4
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://kornelix.squarespace.com/storage/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kornelix.squarespace.com/fotoxx/
COMMENT=	Program for editing image files from a digital camera

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils
DEPENDS+=	p5-Image-ExifTool-[0-9]*:../../graphics/p5-Image-ExifTool
DEPENDS+=	gimp-ufraw-[0-9]*:../../graphics/gimp-ufraw

#WRKSRC=		${WRKDIR}/fotoxx
USE_LANGUAGES=	c++
USE_TOOLS+=	gmake pkg-config

BUILD_TARGET=	fotoxx
INSTALL_TARGET=	install manpage # XXX menu

.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
