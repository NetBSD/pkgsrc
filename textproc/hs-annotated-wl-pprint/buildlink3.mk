# $NetBSD: buildlink3.mk,v 1.4 2022/02/12 08:50:50 pho Exp $

BUILDLINK_TREE+=	hs-annotated-wl-pprint

.if !defined(HS_ANNOTATED_WL_PPRINT_BUILDLINK3_MK)
HS_ANNOTATED_WL_PPRINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-annotated-wl-pprint+=	hs-annotated-wl-pprint>=0.7.0
BUILDLINK_ABI_DEPENDS.hs-annotated-wl-pprint+=	hs-annotated-wl-pprint>=0.7.0nb3
BUILDLINK_PKGSRCDIR.hs-annotated-wl-pprint?=	../../textproc/hs-annotated-wl-pprint
.endif	# HS_ANNOTATED_WL_PPRINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-annotated-wl-pprint
