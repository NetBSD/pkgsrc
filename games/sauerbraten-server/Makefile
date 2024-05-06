# $NetBSD: Makefile,v 1.1 2024/05/06 08:07:30 nia Exp $

BUILD_TARGET=	master server

.include "../../games/sauerbraten/Makefile.common"

PKGNAME:=	${PKGNAME:S,sauerbraten-,sauerbraten-server-,g}
COMMENT=	First-person shooter game based on Cube 2 (server)

CONFLICTS+=	sauerbraten-[0-9]*

.include "../../mk/bsd.pkg.mk"
