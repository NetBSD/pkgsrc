# $NetBSD: Makefile,v 1.10 2004/06/15 13:24:44 markd Exp $
#

DISTNAME=	pixieplus-0.5.4
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://people.fruitsalad.org/avleeuwen/distfiles/pixieplus/ \
		http://www.mosfet.org/pixie/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.mosfet.org/pixie/
COMMENT=	Free, fast, and feature packed image browser for KDE

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES

.include "../../graphics/kdegraphics3/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"

.include "../../mk/bsd.pkg.mk"
