# $NetBSD: Makefile,v 1.4 2001/01/11 21:05:49 dent Exp $
#

DISTNAME=	lbreakout-001018
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://lgames.sourceforge.net/

DEPENDS+=	SDL>=1.1.5nb1:../../devel/SDL

USE_X11=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-sdl-prefix=${PREFIX}
CONFIGURE_ARGS+=--disable-sound

.include "../../mk/bsd.pkg.mk"
