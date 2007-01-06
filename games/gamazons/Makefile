# $NetBSD: Makefile,v 1.1.1.1 2007/01/06 02:07:50 wiz Exp $
#

DISTNAME=	gamazons-0.83
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
