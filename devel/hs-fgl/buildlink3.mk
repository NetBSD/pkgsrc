# $NetBSD: buildlink3.mk,v 1.15 2025/03/05 03:39:10 pho Exp $

BUILDLINK_TREE+=	hs-fgl

.if !defined(HS_FGL_BUILDLINK3_MK)
HS_FGL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fgl+=	hs-fgl>=5.8.3
BUILDLINK_ABI_DEPENDS.hs-fgl+=	hs-fgl>=5.8.3.0nb2
BUILDLINK_PKGSRCDIR.hs-fgl?=	../../devel/hs-fgl
.endif	# HS_FGL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fgl
