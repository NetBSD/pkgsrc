# $NetBSD: Makefile,v 1.8 2004/04/25 23:05:52 snj Exp $
#

DISTNAME=	pixieplus-0.5.4
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://people.fruitsalad.org/avleeuwen/distfiles/pixieplus/ \
		http://www.mosfet.org/pixie/

MAINTAINER=	xtraeme@NetBSD.org
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

.include "../../mk/bsd.pkg.mk"
