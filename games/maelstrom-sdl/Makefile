# $NetBSD: Makefile,v 1.1.1.1 2002/07/11 13:21:27 wiz Exp $
#

DISTNAME=	Maelstrom-3.0.5
PKGNAME=	maelstrom-sdl-3.0.5
CATEGORIES=	games x11
MASTER_SITES=	http://www.devolution.com/~slouken/Maelstrom/src/

MAINTAINER=	Benjamin.Wong@cc.gatech.edu
HOMEPAGE=	http://www.devolution.com/~slouken/Maelstrom/
COMMENT=	Incredible, fast moving, high resolution version of asteroids (SDL version)

CONFLICTS=		maelstrom-x11-[0-9]* maelstrom-[0-9]*
USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

post-install:
	${RM} ${PREFIX}/share/doc/Maelstrom/Docs/Makefile \
		${PREFIX}/share/doc/Maelstrom/Docs/Makefile.in \
		${PREFIX}/share/Maelstrom/Images/Makefile \
		${PREFIX}/share/Maelstrom/Images/Makefile.in

.include "../../devel/SDL/buildlink.mk"
.include "../../net/SDL_net/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
