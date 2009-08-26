# $NetBSD: Makefile,v 1.12 2009/08/26 19:57:36 sno Exp $
#

DISTNAME=	blinkenthemes-0.8
PKGREVISION=	6
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
