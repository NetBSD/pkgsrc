# $NetBSD: Makefile,v 1.13 2010/11/15 22:57:01 abs Exp $
#

DISTNAME=	gamazons-0.83
PKGREVISION=	10
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
