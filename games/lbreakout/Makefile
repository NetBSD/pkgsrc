# $NetBSD: Makefile,v 1.3 2000/11/11 17:49:25 tron Exp $
#

DISTNAME=	lbreakout-001018
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://lgames.sourceforge.net/lbreakout/lbreakout.html

DEPENDS+=	SDL>=1.1.5nb1:../../devel/SDL

USE_X11=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-sdl-prefix=${PREFIX}
CONFIGURE_ARGS+=--disable-sound

.include "../../mk/bsd.pkg.mk"
