# $NetBSD: Makefile,v 1.24 2006/05/18 20:29:59 wiz Exp $
#

DISTNAME=	pixieplus-0.5.4
PKGREVISION=	12
CATEGORIES=	graphics
MASTER_SITES=	http://people.fruitsalad.org/avleeuwen/distfiles/pixieplus/ \
		http://www.mosfet.org/pixie/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mosfet.org/pixie/
COMMENT=	Free, fast, and feature packed image browser for KDE

BROKEN_IN=	pkgsrc-2006Q1

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/kdegraphics3/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
