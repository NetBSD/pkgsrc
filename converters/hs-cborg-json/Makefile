# $NetBSD: Makefile,v 1.2 2022/02/26 03:57:44 pho Exp $

DISTNAME=	cborg-json-0.2.3.0
PKGREVISION=	1
CATEGORIES=	converters

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Library for encoding JSON as CBOR
LICENSE=	modified-bsd

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../converters/hs-aeson-pretty/buildlink3.mk"
.include "../../devel/hs-cborg/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
