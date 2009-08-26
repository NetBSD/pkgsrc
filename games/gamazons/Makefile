# $NetBSD: Makefile,v 1.9 2009/08/26 19:57:30 sno Exp $
#

DISTNAME=	gamazons-0.83
PKGREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://www.yorgalily.org/gamazons/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.yorgalily.org/gamazons/
COMMENT=	GNOME program for playing the game Amazons

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
