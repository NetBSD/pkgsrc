# $NetBSD: buildlink3.mk,v 1.1 2020/03/30 16:41:41 riastradh Exp $

BUILDLINK_TREE+=	hs-uglymemo

.if !defined(HS_UGLYMEMO_BUILDLINK3_MK)
HS_UGLYMEMO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-uglymemo+=	hs-uglymemo>=0.1.0.1
BUILDLINK_ABI_DEPENDS.hs-uglymemo+=	hs-uglymemo>=0.1.0.1
BUILDLINK_PKGSRCDIR.hs-uglymemo?=	../../devel/hs-uglymemo
.endif	# HS_UGLYMEMO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-uglymemo
