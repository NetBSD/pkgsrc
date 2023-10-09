# $NetBSD: Makefile,v 1.12 2023/10/09 04:54:44 pho Exp $

DISTNAME=	cryptohash-sha256-0.11.102.1
PKGREVISION=	4
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	Fast, pure and practical SHA-256 implementation
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
