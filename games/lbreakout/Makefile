# $NetBSD: Makefile,v 1.1.1.1 2000/10/22 16:58:12 rh Exp $
#

DISTNAME=	lbreakout-001018
CATEGORIES=	games
MASTER_SITES=	http://download.sourceforge.net/lgames/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://lgames.sourceforge.net/lbreakout/lbreakout.html

DEPENDS+=	SDL>=1.1.5nb1:../../devel/SDL

USE_X11=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-sdl-prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
