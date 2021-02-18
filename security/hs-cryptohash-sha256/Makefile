# $NetBSD: Makefile,v 1.3 2021/02/18 15:07:27 mef Exp $

DISTNAME=	cryptohash-sha256-0.11.101.0
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	Fast, pure and practical SHA-256 implementation
LICENSE=	modified-bsd

BUILDLINK_API_DEPENDS.ghc+=	ghc<8.10
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
