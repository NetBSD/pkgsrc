# $NetBSD: Makefile,v 1.5 2001/08/01 18:19:11 wiz Exp $
#

DISTNAME=	gnome-breakout-0.5.2
CATEGORIES=	games gnome
MASTER_SITES=	http://www.senet.com.au/~alcaron/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.senet.com.au/~alcaron/software.html
COMMENT=	gnome version of the classic breakout game

DEPENDS+=	gnome-core-*:../../x11/gnome-core

GNU_CONFIGURE=	YES
USE_X11BASE=	YES

post-install:
	${TOUCH} /var/games/gnome-breakout.scores
	${CHOWN} games:games /var/games/gnome-breakout.scores
	${CHMOD} 664 /var/games/gnome-breakout.scores

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
