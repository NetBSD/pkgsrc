# $NetBSD: Makefile,v 1.14 2003/11/12 01:31:49 salo Exp $
#

DISTNAME=	gnome-breakout-0.5.2
PKGREVISION=	5
CATEGORIES=	games gnome
MASTER_SITES=	http://www.senet.com.au/~alcaron/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.senet.com.au/~alcaron/software.html
COMMENT=	Gnome version of the classic breakout game

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES

post-install:
	${TOUCH} /var/games/gnome-breakout.scores
	${CHOWN} games:games /var/games/gnome-breakout.scores
	${CHMOD} 664 /var/games/gnome-breakout.scores

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
