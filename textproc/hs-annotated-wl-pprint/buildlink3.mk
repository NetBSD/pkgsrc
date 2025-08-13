# $NetBSD: buildlink3.mk,v 1.12 2025/08/13 11:07:27 pho Exp $

BUILDLINK_TREE+=	hs-annotated-wl-pprint

.if !defined(HS_ANNOTATED_WL_PPRINT_BUILDLINK3_MK)
HS_ANNOTATED_WL_PPRINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-annotated-wl-pprint+=	hs-annotated-wl-pprint>=0.7.0
BUILDLINK_ABI_DEPENDS.hs-annotated-wl-pprint+=	hs-annotated-wl-pprint>=0.7.0nb11
BUILDLINK_PKGSRCDIR.hs-annotated-wl-pprint?=	../../textproc/hs-annotated-wl-pprint
.endif	# HS_ANNOTATED_WL_PPRINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-annotated-wl-pprint
