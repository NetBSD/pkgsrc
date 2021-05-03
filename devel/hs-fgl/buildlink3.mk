# $NetBSD: buildlink3.mk,v 1.3 2021/05/03 19:00:58 pho Exp $

BUILDLINK_TREE+=	hs-fgl

.if !defined(HS_FGL_BUILDLINK3_MK)
HS_FGL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fgl+=	hs-fgl>=5.7.0
BUILDLINK_ABI_DEPENDS.hs-fgl+=	hs-fgl>=5.7.0.3nb1
BUILDLINK_PKGSRCDIR.hs-fgl?=	../../devel/hs-fgl
.endif	# HS_FGL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fgl
