# $NetBSD: Makefile,v 1.10 2025/08/13 11:07:38 pho Exp $

DISTNAME=	typst-0.8.0.1
PKGREVISION=	1
CATEGORIES=	textproc
DIST_SUBDIR=	hs-typst # So that it won't conflict with textproc/typst

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Parsing and evaluating typst syntax
LICENSE=	modified-bsd

.include "../../textproc/hs-typst-symbols/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../devel/hs-ordered-containers/buildlink3.mk"
.include "../../textproc/hs-cassava/buildlink3.mk"
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../textproc/hs-toml-parser/buildlink3.mk"
.include "../../textproc/hs-xml-conduit/buildlink3.mk"
.include "../../textproc/hs-yaml/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
