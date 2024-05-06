# $NetBSD: Makefile,v 1.2 2024/05/06 14:04:26 nia Exp $

BUILD_TARGET=	server

.include "../../games/assaultcube/Makefile.common"

PKGNAME:=	${PKGNAME:S,assaultcube-,assaultcube-server-,g}

COMMENT=	Cube-based FPS with realistic environments (server only)

CONFLICTS+=	assaultcube-[0-9]*

.include "../../mk/bsd.pkg.mk"
