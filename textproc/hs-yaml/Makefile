# $NetBSD: Makefile,v 1.15 2023/11/02 06:37:42 pho Exp $

DISTNAME=	yaml-0.11.11.2
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Support for parsing and rendering YAML document
LICENSE=	modified-bsd

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../textproc/hs-libyaml/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
