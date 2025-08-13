# $NetBSD: Makefile,v 1.11 2025/08/13 11:07:20 pho Exp $

DISTNAME=	cryptohash-md5-0.11.101.0
PKGREVISION=	8
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Fast, pure and practical MD5 implementation
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base \
	bytestring

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
