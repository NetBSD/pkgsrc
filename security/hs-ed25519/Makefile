# $NetBSD: Makefile,v 1.3 2021/02/18 15:07:27 mef Exp $

DISTNAME=	ed25519-0.0.5.0
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	Ed25519 cryptographic signatures
LICENSE=	mit

BUILDLINK_API_DEPENDS.ghc+=	ghc<8.10
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
