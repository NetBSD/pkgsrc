# $NetBSD: buildlink3.mk,v 1.13 2025/03/05 03:39:55 pho Exp $

BUILDLINK_TREE+=	hs-ansi-wl-pprint

.if !defined(HS_ANSI_WL_PPRINT_BUILDLINK3_MK)
HS_ANSI_WL_PPRINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ansi-wl-pprint+=	hs-ansi-wl-pprint>=1.0.2
BUILDLINK_ABI_DEPENDS.hs-ansi-wl-pprint+=	hs-ansi-wl-pprint>=1.0.2nb4
BUILDLINK_PKGSRCDIR.hs-ansi-wl-pprint?=		../../textproc/hs-ansi-wl-pprint

.include "../../textproc/hs-prettyprinter-compat-ansi-wl-pprint/buildlink3.mk"
.endif	# HS_ANSI_WL_PPRINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ansi-wl-pprint
