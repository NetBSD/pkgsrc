# $NetBSD: Makefile,v 1.4 2003/05/05 19:05:12 jmmv Exp $
#

DISTNAME=	Maelstrom-3.0.5
PKGNAME=	maelstrom-sdl-3.0.5
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	http://www.devolution.com/~slouken/Maelstrom/src/

MAINTAINER=	Benjamin.Wong@cc.gatech.edu
HOMEPAGE=	http://www.devolution.com/~slouken/Maelstrom/
COMMENT=	Incredible, fast moving, high resolution version of asteroids (SDL version)

CONFLICTS=		maelstrom-x11-[0-9]* maelstrom-[0-9]*

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES

post-install:
	${RM} ${PREFIX}/share/doc/Maelstrom/Docs/Makefile \
		${PREFIX}/share/doc/Maelstrom/Docs/Makefile.in \
		${PREFIX}/share/Maelstrom/Images/Makefile \
		${PREFIX}/share/Maelstrom/Images/Makefile.in

.include "../../devel/SDL/buildlink2.mk"
.include "../../net/SDL_net/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
