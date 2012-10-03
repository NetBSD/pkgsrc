# $NetBSD: Makefile,v 1.22.2.1 2012/10/03 12:07:35 spz Exp $
#

DISTNAME=	blinkensim-2.2
PKGREVISION=	17
CATEGORIES=	emulators graphics
MASTER_SITES=	http://sven.gimp.org/blinkenlights/old/

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.blinkenlights.de/
COMMENT=	Blinkenlights graphics simulator

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	blinkenthemes>=0.8:../../graphics/blinkenthemes

GNU_CONFIGURE=	YES
USE_TOOLS+=	pkg-config

post-install:
	ln -s blinkensim-gtk ${DESTDIR}${PREFIX}/bin/blinkensim

.include "../../devel/blib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
