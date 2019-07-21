# $NetBSD: Makefile,v 1.41 2019/07/21 22:24:45 wiz Exp $
#

DISTNAME=	blinkensim-2.2
PKGREVISION=	34
CATEGORIES=	emulators graphics
MASTER_SITES=	http://sven.gimp.org/blinkenlights/old/

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.blinkenlights.de/
COMMENT=	Blinkenlights graphics simulator

DEPENDS+=	blinkenthemes>=0.8:../../graphics/blinkenthemes

GNU_CONFIGURE=	YES
USE_TOOLS+=	pkg-config

post-install:
	ln -s blinkensim-gtk ${DESTDIR}${PREFIX}/bin/blinkensim

.include "../../devel/blib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
