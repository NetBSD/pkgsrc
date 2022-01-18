# $NetBSD: buildlink3.mk,v 1.4 2022/01/18 02:48:17 pho Exp $

BUILDLINK_TREE+=	hledger-lib

.if !defined(HLEDGER_LIB_BUILDLINK3_MK)
HLEDGER_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hledger-lib+=	hledger-lib>=1.21
BUILDLINK_ABI_DEPENDS.hledger-lib+=	hledger-lib>=1.21nb2
BUILDLINK_PKGSRCDIR.hledger-lib?=	../../finance/hledger-lib

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../converters/hs-aeson-pretty/buildlink3.mk"
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../devel/hs-base-compat-batteries/buildlink3.mk"
.include "../../textproc/hs-blaze-markup/buildlink3.mk"
.include "../../devel/hs-call-stack/buildlink3.mk"
.include "../../textproc/hs-cassava/buildlink3.mk"
.include "../../textproc/hs-cassava-megaparsec/buildlink3.mk"
.include "../../devel/hs-cmdargs/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../finance/hs-Decimal/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-file-embed/buildlink3.mk"
.include "../../textproc/hs-Glob/buildlink3.mk"
.include "../../devel/hs-hashtables/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../time/hs-old-time/buildlink3.mk"
.include "../../devel/hs-parser-combinators/buildlink3.mk"
.include "../../devel/hs-pretty-simple/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../devel/hs-tabular/buildlink3.mk"
.include "../../devel/hs-tasty/buildlink3.mk"
.include "../../devel/hs-tasty-hunit/buildlink3.mk"
.include "../../devel/hs-timeit/buildlink3.mk"
.include "../../devel/hs-uglymemo/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.endif	# HLEDGER_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-hledger-lib
