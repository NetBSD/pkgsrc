# $NetBSD: Makefile,v 1.17 2006/05/22 21:58:33 wiz Exp $
#

DISTNAME=	Maelstrom-3.0.5
PKGNAME=	maelstrom-sdl-3.0.5
PKGREVISION=	6
CATEGORIES=	games x11
MASTER_SITES=	http://www.devolution.com/~slouken/Maelstrom/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.devolution.com/~slouken/Maelstrom/
COMMENT=	High resolution version of Asteroids (SDL version)

CONFLICTS=		maelstrom-x11-[0-9]* maelstrom-[0-9]*

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++

MAKE_ENV+=		CP=${CP:Q}

post-install:
	${RM} ${PREFIX}/share/doc/Maelstrom/Docs/Makefile \
		${PREFIX}/share/doc/Maelstrom/Docs/Makefile.in \
		${PREFIX}/share/Maelstrom/Images/Makefile \
		${PREFIX}/share/Maelstrom/Images/Makefile.in

.include "../../devel/SDL/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
