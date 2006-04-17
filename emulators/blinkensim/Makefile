# $NetBSD: Makefile,v 1.10 2006/04/17 13:46:23 wiz Exp $
#

DISTNAME=	blinkensim-2.2
PKGREVISION=	5
CATEGORIES=	emulators graphics
MASTER_SITES=	http://sven.gimp.org/blinkenlights/old/

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.blinkenlights.de/
COMMENT=	Blinkenlights graphics simulator

DEPENDS+=	blinkenthemes>=0.8:../../graphics/blinkenthemes

GNU_CONFIGURE=	YES
USE_TOOLS+=	pkg-config

post-install:
	cd ${PREFIX}/bin && ${LN} -s blinkensim-gtk blinkensim

.include "../../devel/blib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
