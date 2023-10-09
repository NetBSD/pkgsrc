# $NetBSD: buildlink3.mk,v 1.7 2023/10/09 04:54:48 pho Exp $

BUILDLINK_TREE+=	hs-annotated-wl-pprint

.if !defined(HS_ANNOTATED_WL_PPRINT_BUILDLINK3_MK)
HS_ANNOTATED_WL_PPRINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-annotated-wl-pprint+=	hs-annotated-wl-pprint>=0.7.0
BUILDLINK_ABI_DEPENDS.hs-annotated-wl-pprint+=	hs-annotated-wl-pprint>=0.7.0nb6
BUILDLINK_PKGSRCDIR.hs-annotated-wl-pprint?=	../../textproc/hs-annotated-wl-pprint
.endif	# HS_ANNOTATED_WL_PPRINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-annotated-wl-pprint
