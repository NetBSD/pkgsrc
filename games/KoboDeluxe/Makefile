# $NetBSD: Makefile,v 1.13 2005/12/11 09:40:40 wiz Exp $

DISTNAME=	KoboDeluxe-0.4pre8
PKGNAME=	${DISTNAME:S/pre/rc/}
PKGREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://olofson.net/kobodl/download/

MAINTAINER=	as@rsn.bth.se
HOMEPAGE=	http://olofson.net/kobodl/
COMMENT=	Multi-way scrolling shoot 'em up game for X

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
