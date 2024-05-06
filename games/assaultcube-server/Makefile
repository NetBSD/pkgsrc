# $NetBSD: Makefile,v 1.3 2024/05/06 17:30:50 nia Exp $

BUILD_TARGET=	server

.include "../../games/assaultcube/Makefile.common"

PKGNAME:=	${PKGNAME:S,assaultcube-,assaultcube-server-,g}

COMMENT=	Cube-based FPS with realistic environments (server only)

CONFLICTS+=	assaultcube-[0-9]*

# assaultcube's server wants SDL2 on darwin for the thread functions
# so just use the main package
NOT_FOR_PLATFORM+=	Darwin-*-*

.include "../../mk/bsd.pkg.mk"
