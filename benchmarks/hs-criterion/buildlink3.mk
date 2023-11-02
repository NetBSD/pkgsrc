# $NetBSD: buildlink3.mk,v 1.1 2023/11/02 02:50:25 pho Exp $

BUILDLINK_TREE+=	hs-criterion

.if !defined(HS_CRITERION_BUILDLINK3_MK)
HS_CRITERION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-criterion+=	hs-criterion>=1.6.3
BUILDLINK_ABI_DEPENDS.hs-criterion+=	hs-criterion>=1.6.3.0
BUILDLINK_PKGSRCDIR.hs-criterion?=	../../benchmarks/hs-criterion

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
.endif	# HS_CRITERION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-criterion
