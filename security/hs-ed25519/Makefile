# $NetBSD: Makefile,v 1.11 2023/10/09 04:54:44 pho Exp $

DISTNAME=	ed25519-0.0.5.0
PKGREVISION=	6
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	Ed25519 cryptographic signatures
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	ghc-prim	\
	bytestring

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
