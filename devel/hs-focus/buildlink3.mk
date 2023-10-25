# $NetBSD: buildlink3.mk,v 1.5 2023/10/25 10:12:06 pho Exp $

BUILDLINK_TREE+=	hs-focus

.if !defined(HS_FOCUS_BUILDLINK3_MK)
HS_FOCUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-focus+=	hs-focus>=1.0.3
BUILDLINK_ABI_DEPENDS.hs-focus+=	hs-focus>=1.0.3.2
BUILDLINK_PKGSRCDIR.hs-focus?=		../../devel/hs-focus
.endif	# HS_FOCUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-focus
