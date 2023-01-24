# $NetBSD: Makefile,v 1.9 2023/01/24 12:33:26 pho Exp $

DISTNAME=	ed25519-0.0.5.0
PKGREVISION=	4
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	Ed25519 cryptographic signatures
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	ghc-prim	\
	bytestring

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
