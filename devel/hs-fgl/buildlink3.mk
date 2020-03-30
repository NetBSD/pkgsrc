# $NetBSD: buildlink3.mk,v 1.1 2020/03/30 16:36:48 riastradh Exp $

BUILDLINK_TREE+=	hs-fgl

.if !defined(HS_FGL_BUILDLINK3_MK)
HS_FGL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fgl+=	hs-fgl>=5.7.0.2
BUILDLINK_ABI_DEPENDS.hs-fgl+=	hs-fgl>=5.7.0.2
BUILDLINK_PKGSRCDIR.hs-fgl?=	../../devel/hs-fgl
.endif	# HS_FGL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fgl
