# $NetBSD: buildlink3.mk,v 1.18 2025/03/05 03:39:58 pho Exp $

BUILDLINK_TREE+=	hs-doctemplates

.if !defined(HS_DOCTEMPLATES_BUILDLINK3_MK)
HS_DOCTEMPLATES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-doctemplates+=	hs-doctemplates>=0.11.0
BUILDLINK_ABI_DEPENDS.hs-doctemplates+=	hs-doctemplates>=0.11.0.1nb2
BUILDLINK_PKGSRCDIR.hs-doctemplates?=	../../textproc/hs-doctemplates

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-doclayout/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../converters/hs-text-conversions/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_DOCTEMPLATES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-doctemplates
