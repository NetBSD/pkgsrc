# $NetBSD: Makefile,v 1.1.1.1 2003/07/12 09:30:40 zuntum Exp $

DISTNAME=	KoboDeluxe-0.4pre8
CATEGORIES=	games
MASTER_SITES=	http://olofson.net/kobodl/download/

MAINTAINER=	as@rsn.bth.se
HOMEPAGE=	http://olofson.net/kobodl/
COMMENT=	Multi-way scrolling shoot 'em up game for X

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES

.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/SDL_image/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
