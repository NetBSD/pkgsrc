# $NetBSD: buildlink3.mk,v 1.11 2023/11/02 06:36:29 pho Exp $

BUILDLINK_TREE+=	hs-fgl

.if !defined(HS_FGL_BUILDLINK3_MK)
HS_FGL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fgl+=	hs-fgl>=5.8.2
BUILDLINK_ABI_DEPENDS.hs-fgl+=	hs-fgl>=5.8.2.0nb1
BUILDLINK_PKGSRCDIR.hs-fgl?=	../../devel/hs-fgl
.endif	# HS_FGL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fgl
