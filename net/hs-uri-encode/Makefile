# $NetBSD: Makefile,v 1.11 2026/11/13 14:39:40 pho Exp $

DISTNAME=	uri-encode-1.5.0.7
PKGREVISION=	9
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Unicode aware uri-encoding
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	bytestring	\
	text

.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
