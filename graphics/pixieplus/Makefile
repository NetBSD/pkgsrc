# $NetBSD: Makefile,v 1.37 2009/12/09 12:40:10 joerg Exp $
#

DISTNAME=	pixieplus-0.5.4
PKGREVISION=	21
CATEGORIES=	graphics
MASTER_SITES=	http://people.fruitsalad.org/avleeuwen/distfiles/pixieplus/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mosfet.org/pixie/
COMMENT=	Free, fast, and feature packed image browser for KDE

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=	-I${BUILDLINK_PREFIX.ImageMagick}/include/ImageMagick

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/kdegraphics3/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
