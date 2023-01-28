# $NetBSD: Makefile,v 1.1 2023/01/28 18:23:35 pho Exp $

DISTNAME=	base64-0.4.2.4
CATEGORIES=	converters

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Modern RFC 4648-compliant Base64 library
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	text

.include "../../textproc/hs-text-short/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
