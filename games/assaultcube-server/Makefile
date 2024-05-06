# $NetBSD: Makefile,v 1.1 2024/05/06 07:46:35 nia Exp $

BUILD_TARGET=	master server

.include "../../games/assaultcube/Makefile.common"

PKGNAME:=	${PKGNAME:S,assaultcube-,assaultcube-server-,g}

COMMENT=	Cube-based FPS with realistic environments (server only)

CONFLICTS+=	assaultcube-[0-9]*

.include "../../mk/bsd.pkg.mk"
