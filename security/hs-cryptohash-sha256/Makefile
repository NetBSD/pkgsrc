# $NetBSD: Makefile,v 1.11 2023/02/07 01:41:03 pho Exp $

DISTNAME=	cryptohash-sha256-0.11.102.1
PKGREVISION=	3
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	Fast, pure and practical SHA-256 implementation
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
