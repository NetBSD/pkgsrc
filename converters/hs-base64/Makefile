# $NetBSD: Makefile,v 1.14 2026/11/13 14:38:41 pho Exp $

DISTNAME=	base64-1.0
PKGREVISION=	5
CATEGORIES=	converters

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Modern RFC 4648-compliant Base64 library
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base

.include "../../textproc/hs-text-short/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
