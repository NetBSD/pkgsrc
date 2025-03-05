# $NetBSD: Makefile,v 1.15 2025/03/05 03:39:50 pho Exp $

DISTNAME=	ed25519-0.0.5.0
PKGREVISION=	10
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	Ed25519 cryptographic signatures
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	ghc-prim	\
	bytestring

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
