# $NetBSD: buildlink3.mk,v 1.3 2022/08/20 08:08:13 wiz Exp $

BUILDLINK_TREE+=	hs-basic-prelude

.if !defined(HS_BASIC_PRELUDE_BUILDLINK3_MK)
HS_BASIC_PRELUDE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-basic-prelude+=	hs-basic-prelude>=0.7.0
BUILDLINK_ABI_DEPENDS.hs-basic-prelude+=	hs-basic-prelude>=0.7.0nb2
BUILDLINK_PKGSRCDIR.hs-basic-prelude?=		../../devel/hs-basic-prelude

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_BASIC_PRELUDE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-basic-prelude
