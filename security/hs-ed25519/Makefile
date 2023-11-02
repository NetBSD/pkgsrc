# $NetBSD: Makefile,v 1.12 2023/11/02 06:37:21 pho Exp $

DISTNAME=	ed25519-0.0.5.0
PKGREVISION=	7
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	Ed25519 cryptographic signatures
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	ghc-prim	\
	bytestring

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
