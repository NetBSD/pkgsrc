# $NetBSD: Makefile,v 1.7 2004/03/06 21:12:37 snj Exp $

DISTNAME=	KoboDeluxe-0.4pre8
PKGNAME=	${DISTNAME:S/pre/rc/}
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://olofson.net/kobodl/download/

MAINTAINER=	as@rsn.bth.se
HOMEPAGE=	http://olofson.net/kobodl/
COMMENT=	Multi-way scrolling shoot 'em up game for X

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
USE_X11=	YES

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
