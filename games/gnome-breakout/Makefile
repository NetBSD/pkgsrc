# $NetBSD: Makefile,v 1.17 2004/03/26 02:27:40 wiz Exp $
#

DISTNAME=	gnome-breakout-0.5.2
PKGREVISION=	8
CATEGORIES=	games gnome
MASTER_SITES=	http://www.senet.com.au/~alcaron/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.senet.com.au/~alcaron/software.html
COMMENT=	Gnome version of the classic breakout game

DEPENDS+=	xdg-x11-dirs>=1.1:../../misc/xdg-x11-dirs

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
