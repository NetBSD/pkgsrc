# $NetBSD: buildlink3.mk,v 1.5 2022/02/12 08:50:32 pho Exp $

BUILDLINK_TREE+=	hs-fgl

.if !defined(HS_FGL_BUILDLINK3_MK)
HS_FGL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fgl+=	hs-fgl>=5.7.0
BUILDLINK_ABI_DEPENDS.hs-fgl+=	hs-fgl>=5.7.0.3nb3
BUILDLINK_PKGSRCDIR.hs-fgl?=	../../devel/hs-fgl
.endif	# HS_FGL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fgl
