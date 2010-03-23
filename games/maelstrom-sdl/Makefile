# $NetBSD: Makefile,v 1.19 2010/03/23 16:02:39 joerg Exp $
#

DISTNAME=	Maelstrom-3.0.5
PKGNAME=	maelstrom-sdl-3.0.5
PKGREVISION=	7
CATEGORIES=	games x11
MASTER_SITES=	http://www.devolution.com/~slouken/Maelstrom/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.devolution.com/~slouken/Maelstrom/
COMMENT=	High resolution version of Asteroids (SDL version)

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		maelstrom-x11-[0-9]* maelstrom-[0-9]*

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++

MAKE_ENV+=		CP=${CP:Q}

post-install:
	${RM} ${DESTDIR}${PREFIX}/share/doc/Maelstrom/Docs/Makefile \
		${DESTDIR}${PREFIX}/share/doc/Maelstrom/Docs/Makefile.in \
		${DESTDIR}${PREFIX}/share/Maelstrom/Images/Makefile \
		${DESTDIR}${PREFIX}/share/Maelstrom/Images/Makefile.in

.include "../../devel/SDL/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
