# $NetBSD: Makefile,v 1.22 2012/09/15 10:04:46 obache Exp $
#

DISTNAME=	blinkenthemes-0.8
PKGREVISION=	16
CATEGORIES=	graphics
MASTER_SITES=	http://sven.gimp.org/blinkenlights/old/

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.blinkenlights.de/
COMMENT=	Blinkenlights simulator themes

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_TOOLS+=	pkg-config

.include "../../devel/blib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
