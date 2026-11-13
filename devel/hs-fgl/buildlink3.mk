# $NetBSD: buildlink3.mk,v 1.17 2026/11/13 14:38:57 pho Exp $

BUILDLINK_TREE+=	hs-fgl

.if !defined(HS_FGL_BUILDLINK3_MK)
HS_FGL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fgl+=	hs-fgl>=5.8.3
BUILDLINK_ABI_DEPENDS.hs-fgl+=	hs-fgl>=5.8.3.0nb4
BUILDLINK_PKGSRCDIR.hs-fgl?=	../../devel/hs-fgl
.endif	# HS_FGL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fgl
