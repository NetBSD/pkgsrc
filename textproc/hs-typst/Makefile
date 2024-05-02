# $NetBSD: Makefile,v 1.3 2024/05/02 10:49:38 pho Exp $

DISTNAME=	typst-0.5.0.3
CATEGORIES=	textproc print
DIST_SUBDIR=	hs-typst # So that it won't conflict with textproc/typst

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Parsing and evaluating typst syntax
LICENSE=	modified-bsd

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-cassava/buildlink3.mk"
.include "../../devel/hs-ordered-containers/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../textproc/hs-toml-parser/buildlink3.mk"
.include "../../textproc/hs-typst-symbols/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../textproc/hs-xml-conduit/buildlink3.mk"
.include "../../textproc/hs-yaml/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
