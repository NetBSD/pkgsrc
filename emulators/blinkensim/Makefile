# $NetBSD: Makefile,v 1.3 2004/04/16 04:09:19 salo Exp $
#

DISTNAME=	blinkensim-2.2
PKGREVISION=	1
CATEGORIES=	emulators graphics
MASTER_SITES=	http://sven.gimp.org/blinkenlights/old/

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.blinkenlights.de/
COMMENT=	Blinkenlights graphics simulator

DEPENDS+=	blinkenthemes>=0.8:../../graphics/blinkenthemes

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

post-install:
	cd ${PREFIX}/bin && ${LN} -s blinkensim-gtk blinkensim

.include "../../devel/blib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
