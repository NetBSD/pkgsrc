# $NetBSD: Makefile,v 1.8 2023/10/30 18:57:19 pho Exp $

DISTNAME=	cborg-json-0.2.5.0
PKGREVISION=	2
CATEGORIES=	converters

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Library for encoding JSON as CBOR
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	aeson	\
	base	\
	vector

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../converters/hs-aeson-pretty/buildlink3.mk"
.include "../../devel/hs-cborg/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
