# $NetBSD: Makefile,v 1.70 2023/11/08 13:19:13 wiz Exp $
#

DISTNAME=	gamazons-0.83
PKGREVISION=	66
CATEGORIES=	games
MASTER_SITES=	http://www.yorgalily.org/gamazons/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.yorgalily.org/gamazons/
COMMENT=	GNOME program for playing the game Amazons

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
