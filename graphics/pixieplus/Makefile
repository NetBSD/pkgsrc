# $NetBSD: Makefile,v 1.6 2004/02/14 17:21:43 jlam Exp $
#

DISTNAME=	pixieplus-0.5.4
PKGREVISION=	3
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
