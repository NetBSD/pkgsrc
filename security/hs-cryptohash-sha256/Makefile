# $NetBSD: Makefile,v 1.10 2023/01/24 13:06:31 pho Exp $

DISTNAME=	cryptohash-sha256-0.11.102.1
PKGREVISION=	2
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	Fast, pure and practical SHA-256 implementation
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
