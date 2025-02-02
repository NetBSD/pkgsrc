# $NetBSD: Makefile,v 1.16 2025/02/02 13:05:43 pho Exp $

DISTNAME=	cryptohash-sha256-0.11.102.1
PKGREVISION=	7
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	Fast, pure and practical SHA-256 implementation
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base \
	bytestring

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
