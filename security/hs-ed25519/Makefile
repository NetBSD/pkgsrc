# $NetBSD: Makefile,v 1.14 2025/02/02 13:05:44 pho Exp $

DISTNAME=	ed25519-0.0.5.0
PKGREVISION=	9
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	Ed25519 cryptographic signatures
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	ghc-prim	\
	bytestring

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
