# $NetBSD: buildlink3.mk,v 1.7 2023/01/25 01:58:56 pho Exp $

BUILDLINK_TREE+=	hs-fgl

.if !defined(HS_FGL_BUILDLINK3_MK)
HS_FGL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fgl+=	hs-fgl>=5.8.0
BUILDLINK_ABI_DEPENDS.hs-fgl+=	hs-fgl>=5.8.0.0
BUILDLINK_PKGSRCDIR.hs-fgl?=	../../devel/hs-fgl
.endif	# HS_FGL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fgl
