# $NetBSD: buildlink3.mk,v 1.2 2022/01/18 02:48:02 pho Exp $

BUILDLINK_TREE+=	hlint

.if !defined(HLINT_BUILDLINK3_MK)
HLINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hlint+=	hlint>=3.3.1
BUILDLINK_ABI_DEPENDS.hlint+=	hlint>=3.3.1nb1
BUILDLINK_PKGSRCDIR.hlint?=	../../devel/hlint

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../devel/hs-cmdargs/buildlink3.mk"
.include "../../devel/hs-cpphs/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-file-embed/buildlink3.mk"
.include "../../sysutils/hs-filepattern/buildlink3.mk"
.include "../../devel/hs-ghc-lib-parser-ex/buildlink3.mk"
.include "../../devel/hs-refact/buildlink3.mk"
.include "../../devel/hs-uniplate/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../textproc/hs-hscolour/buildlink3.mk"
.include "../../textproc/hs-yaml/buildlink3.mk"
.endif	# HLINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hlint
