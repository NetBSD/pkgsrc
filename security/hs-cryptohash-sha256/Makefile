# $NetBSD: Makefile,v 1.2 2021/02/13 08:00:59 mef Exp $

DISTNAME=	cryptohash-sha256-0.11.101.0
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	Fast, pure and practical SHA-256 implementation
LICENSE=	modified-bsd

BUILDLINK_API_DEPENDS.ghc+=	ghc<9.0
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
