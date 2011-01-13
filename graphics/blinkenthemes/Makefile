# $NetBSD: Makefile,v 1.16 2011/01/13 13:37:56 wiz Exp $
#

DISTNAME=	blinkenthemes-0.8
PKGREVISION=	10
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
