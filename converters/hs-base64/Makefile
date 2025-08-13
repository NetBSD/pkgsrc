# $NetBSD: Makefile,v 1.13 2025/08/13 11:06:24 pho Exp $

DISTNAME=	base64-1.0
PKGREVISION=	4
CATEGORIES=	converters

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Modern RFC 4648-compliant Base64 library
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base

.include "../../textproc/hs-text-short/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
