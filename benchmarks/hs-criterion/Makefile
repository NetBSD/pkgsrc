# $NetBSD: Makefile,v 1.3 2024/05/09 01:31:39 pho Exp $

DISTNAME=	criterion-1.6.3.0
PKGREVISION=	2
CATEGORIES=	benchmarks

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Robust, reliable performance measurement and analysis
LICENSE=	modified-bsd

OPTPARSE_APPLICATIVE_EXECUTABLES+=	criterion-report
.include "../../devel/hs-optparse-applicative/application.mk"

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-base-compat-batteries/buildlink3.mk"
.include "../../devel/hs-binary-orphans/buildlink3.mk"
.include "../../textproc/hs-cassava/buildlink3.mk"
.include "../../devel/hs-code-page/buildlink3.mk"
.include "../../benchmarks/hs-criterion-measurement/buildlink3.mk"
.include "../../textproc/hs-Glob/buildlink3.mk"
.include "../../www/hs-js-chart/buildlink3.mk"
.include "../../textproc/hs-microstache/buildlink3.mk"
.include "../../math/hs-mwc-random/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../textproc/hs-prettyprinter/buildlink3.mk"
.include "../../textproc/hs-prettyprinter-ansi-terminal/buildlink3.mk"
.include "../../math/hs-statistics/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../devel/hs-vector-algorithms/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
