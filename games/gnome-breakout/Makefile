# $NetBSD: Makefile,v 1.20 2004/04/26 04:55:48 snj Exp $
#

DISTNAME=	gnome-breakout-0.5.2
PKGREVISION=	8
CATEGORIES=	games gnome
MASTER_SITES=	http://www.senet.com.au/~alcaron/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.senet.com.au/~alcaron/software.html
COMMENT=	Gnome version of the classic breakout game

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES

post-install:
	${TOUCH} /var/games/gnome-breakout.scores
	${CHOWN} games:games /var/games/gnome-breakout.scores
	${CHMOD} 664 /var/games/gnome-breakout.scores

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gnome-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
