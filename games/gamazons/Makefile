# $NetBSD: Makefile,v 1.3 2007/06/05 05:37:26 wiz Exp $
#

DISTNAME=	gamazons-0.83
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.yorgalily.org/gamazons/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.yorgalily.org/gamazons/
COMMENT=	GNOME program for playing the game Amazons

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_DIRS+=	gnome2-1.6 xdg-1.4

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
