# $NetBSD: Makefile,v 1.15 2024/05/09 01:32:32 pho Exp $

DISTNAME=	cryptohash-sha256-0.11.102.1
PKGREVISION=	6
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	Fast, pure and practical SHA-256 implementation
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base \
	bytestring

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
