# $NetBSD: Makefile,v 1.10 2023/02/07 01:41:04 pho Exp $

DISTNAME=	ed25519-0.0.5.0
PKGREVISION=	5
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	Ed25519 cryptographic signatures
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	ghc-prim	\
	bytestring

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
