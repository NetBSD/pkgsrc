# $NetBSD: Makefile,v 1.8 2004/10/03 00:14:45 tv Exp $
#

DISTNAME=	Maelstrom-3.0.5
PKGNAME=	maelstrom-sdl-3.0.5
PKGREVISION=	3
CATEGORIES=	games x11
MASTER_SITES=	http://www.devolution.com/~slouken/Maelstrom/src/

MAINTAINER=	Benjamin.Wong@cc.gatech.edu
HOMEPAGE=	http://www.devolution.com/~slouken/Maelstrom/
COMMENT=	High resolution version of Asteroids (SDL version)

CONFLICTS=		maelstrom-x11-[0-9]* maelstrom-[0-9]*

USE_BUILDLINK3=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES

MAKE_ENV+=		CP=${CP}

post-install:
	${RM} ${PREFIX}/share/doc/Maelstrom/Docs/Makefile \
		${PREFIX}/share/doc/Maelstrom/Docs/Makefile.in \
		${PREFIX}/share/Maelstrom/Images/Makefile \
		${PREFIX}/share/Maelstrom/Images/Makefile.in

.include "../../devel/SDL/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
