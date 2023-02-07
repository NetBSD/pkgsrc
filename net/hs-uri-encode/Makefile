# $NetBSD: Makefile,v 1.4 2023/02/07 01:41:03 pho Exp $

DISTNAME=	uri-encode-1.5.0.7
PKGREVISION=	2
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
