# $NetBSD: Makefile,v 1.6 2004/01/24 13:30:55 grant Exp $

DISTNAME=	KoboDeluxe-0.4pre8
PKGNAME=	${DISTNAME:S/pre/rc/}
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://olofson.net/kobodl/download/

MAINTAINER=	as@rsn.bth.se
HOMEPAGE=	http://olofson.net/kobodl/
COMMENT=	Multi-way scrolling shoot 'em up game for X

USE_BUILDLINK2=	YES
USE_GNU_TOOLS+=	make
USE_X11=	YES
GNU_CONFIGURE=	YES

.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/SDL_image/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
