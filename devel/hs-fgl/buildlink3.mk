# $NetBSD: buildlink3.mk,v 1.13 2025/01/31 00:17:33 pho Exp $

BUILDLINK_TREE+=	hs-fgl

.if !defined(HS_FGL_BUILDLINK3_MK)
HS_FGL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fgl+=	hs-fgl>=5.8.3
BUILDLINK_ABI_DEPENDS.hs-fgl+=	hs-fgl>=5.8.3.0
BUILDLINK_PKGSRCDIR.hs-fgl?=	../../devel/hs-fgl
.endif	# HS_FGL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fgl
