# $NetBSD: Makefile,v 1.2 2004/01/03 18:49:40 reed Exp $
#

DISTNAME=	blinkensim-2.2
PKGREVISION=	1
CATEGORIES=	emulators graphics
MASTER_SITES=	http://sven.gimp.org/blinkenlights/old/

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.blinkenlights.de/
COMMENT=	Blinkenlights graphics simulator

DEPENDS+=	blinkenthemes>=0.8:../../graphics/blinkenthemes

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

post-install:
	cd ${PREFIX}/bin && ${LN} -s blinkensim-gtk blinkensim

.include "../../devel/blib/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
