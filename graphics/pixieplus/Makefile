# $NetBSD: Makefile,v 1.7 2004/03/26 02:27:42 wiz Exp $
#

DISTNAME=	pixieplus-0.5.4
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://people.fruitsalad.org/avleeuwen/distfiles/pixieplus/ \
		http://www.mosfet.org/pixie/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.mosfet.org/pixie/
COMMENT=	Free, fast, and feature packed image browser for KDE

USE_BUILDLINK2=	YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES

.include "../../graphics/kdegraphics3/buildlink2.mk"
.include "../../graphics/ImageMagick/buildlink2.mk"
.include "../../graphics/libungif/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
