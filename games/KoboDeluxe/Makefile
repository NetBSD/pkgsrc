# $NetBSD: Makefile,v 1.25 2012/01/28 11:00:54 wiz Exp $
#

DISTNAME=	KoboDeluxe-0.5.1
PKGREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://olofson.net/kobodl/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	as@rsn.bth.se
HOMEPAGE=	http://olofson.net/kobodl/
COMMENT=	Multi-way scrolling shoot 'em up game for X
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
BUILD_DEFS+=		VARBASE
CONFIGURE_ARGS+=	--sharedstatedir=${VARBASE}/games

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
