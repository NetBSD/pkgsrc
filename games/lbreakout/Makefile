# $NetBSD: Makefile,v 1.5 2001/02/16 15:10:53 wiz Exp $
#

DISTNAME=	lbreakout-001018
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	breakout-style arcade game

DEPENDS+=	SDL>=1.1.5nb1:../../devel/SDL

USE_X11=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-sdl-prefix=${PREFIX}
CONFIGURE_ARGS+=--disable-sound

.include "../../mk/bsd.pkg.mk"
