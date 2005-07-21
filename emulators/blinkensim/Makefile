# $NetBSD: Makefile,v 1.6 2005/07/21 16:29:49 wiz Exp $
#

DISTNAME=	blinkensim-2.2
PKGREVISION=	2
CATEGORIES=	emulators graphics
MASTER_SITES=	http://sven.gimp.org/blinkenlights/old/

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.blinkenlights.de/
COMMENT=	Blinkenlights graphics simulator

DEPENDS+=	blinkenthemes>=0.8:../../graphics/blinkenthemes

GNU_CONFIGURE=	YES

post-install:
	cd ${PREFIX}/bin && ${LN} -s blinkensim-gtk blinkensim

.include "../../devel/blib/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
