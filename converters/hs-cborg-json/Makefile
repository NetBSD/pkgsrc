# $NetBSD: Makefile,v 1.4 2022/08/29 10:41:02 wiz Exp $

DISTNAME=	cborg-json-0.2.4.0
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
