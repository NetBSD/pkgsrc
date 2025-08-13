# $NetBSD: Makefile,v 1.11 2025/08/13 11:07:21 pho Exp $

DISTNAME=	cryptohash-sha1-0.11.101.0
PKGREVISION=	8
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Fast, pure and practical SHA-1 implementation
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	bytestring

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
