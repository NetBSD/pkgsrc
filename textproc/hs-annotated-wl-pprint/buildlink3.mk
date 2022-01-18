# $NetBSD: buildlink3.mk,v 1.3 2022/01/18 02:48:23 pho Exp $

BUILDLINK_TREE+=	hs-annotated-wl-pprint

.if !defined(HS_ANNOTATED_WL_PPRINT_BUILDLINK3_MK)
HS_ANNOTATED_WL_PPRINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-annotated-wl-pprint+=	hs-annotated-wl-pprint>=0.7.0
BUILDLINK_ABI_DEPENDS.hs-annotated-wl-pprint+=	hs-annotated-wl-pprint>=0.7.0nb2
BUILDLINK_PKGSRCDIR.hs-annotated-wl-pprint?=	../../textproc/hs-annotated-wl-pprint
.endif	# HS_ANNOTATED_WL_PPRINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-annotated-wl-pprint
