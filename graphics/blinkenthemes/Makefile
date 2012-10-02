# $NetBSD: Makefile,v 1.23 2012/10/02 17:11:06 tron Exp $
#

DISTNAME=	blinkenthemes-0.8
PKGREVISION=	17
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
