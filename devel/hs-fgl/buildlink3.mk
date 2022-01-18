# $NetBSD: buildlink3.mk,v 1.4 2022/01/18 02:48:07 pho Exp $

BUILDLINK_TREE+=	hs-fgl

.if !defined(HS_FGL_BUILDLINK3_MK)
HS_FGL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fgl+=	hs-fgl>=5.7.0
BUILDLINK_ABI_DEPENDS.hs-fgl+=	hs-fgl>=5.7.0.3nb2
BUILDLINK_PKGSRCDIR.hs-fgl?=	../../devel/hs-fgl
.endif	# HS_FGL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fgl
