# $NetBSD: Makefile,v 1.7 2024/04/28 12:23:33 pho Exp $

DISTNAME=	cryptohash-md5-0.11.101.0
PKGREVISION=	4
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Fast, pure and practical MD5 implementation
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base \
	bytestring

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
