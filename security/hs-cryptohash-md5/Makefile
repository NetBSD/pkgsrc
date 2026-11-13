# $NetBSD: Makefile,v 1.12 2026/11/13 14:39:41 pho Exp $

DISTNAME=	cryptohash-md5-0.11.101.0
PKGREVISION=	9
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Fast, pure and practical MD5 implementation
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base \
	bytestring

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
