# $NetBSD: Makefile,v 1.2 2000/10/22 18:33:32 rh Exp $
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
CONFIGURE_ARGS+=--disable-sound

.include "../../mk/bsd.pkg.mk"
