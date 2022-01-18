# $NetBSD: buildlink3.mk,v 1.3 2022/01/18 02:48:23 pho Exp $

BUILDLINK_TREE+=	hs-ansi-wl-pprint

.if !defined(HS_ANSI_WL_PPRINT_BUILDLINK3_MK)
HS_ANSI_WL_PPRINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ansi-wl-pprint+=	hs-ansi-wl-pprint>=0.6.9
BUILDLINK_ABI_DEPENDS.hs-ansi-wl-pprint+=	hs-ansi-wl-pprint>=0.6.9nb2
BUILDLINK_PKGSRCDIR.hs-ansi-wl-pprint?=		../../textproc/hs-ansi-wl-pprint

.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.endif	# HS_ANSI_WL_PPRINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ansi-wl-pprint
