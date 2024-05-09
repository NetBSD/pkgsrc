# $NetBSD: Makefile,v 1.13 2024/05/09 01:32:33 pho Exp $

DISTNAME=	ed25519-0.0.5.0
PKGREVISION=	8
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	Ed25519 cryptographic signatures
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	ghc-prim	\
	bytestring

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
