# $NetBSD: Makefile,v 1.19 2008/06/12 02:14:29 joerg Exp $

DISTNAME=	KoboDeluxe-0.4pre10
PKGNAME=	${DISTNAME:S/pre/rc/}
CATEGORIES=	games
MASTER_SITES=	http://olofson.net/kobodl/download/

MAINTAINER=	as@rsn.bth.se
HOMEPAGE=	http://olofson.net/kobodl/
COMMENT=	Multi-way scrolling shoot 'em up game for X

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
CONFIGURE_ENV+=	VARBASE=${VARBASE}

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
