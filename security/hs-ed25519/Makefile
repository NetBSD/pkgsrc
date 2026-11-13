# $NetBSD: Makefile,v 1.17 2026/11/13 14:39:42 pho Exp $

DISTNAME=	ed25519-0.0.5.0
PKGREVISION=	12
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	Ed25519 cryptographic signatures
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	ghc-prim	\
	bytestring

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
