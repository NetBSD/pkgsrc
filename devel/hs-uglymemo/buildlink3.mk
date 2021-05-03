# $NetBSD: buildlink3.mk,v 1.3 2021/05/03 19:01:04 pho Exp $

BUILDLINK_TREE+=	hs-uglymemo

.if !defined(HS_UGLYMEMO_BUILDLINK3_MK)
HS_UGLYMEMO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-uglymemo+=	hs-uglymemo>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-uglymemo+=	hs-uglymemo>=0.1.0.1nb1
BUILDLINK_PKGSRCDIR.hs-uglymemo?=	../../devel/hs-uglymemo
.endif	# HS_UGLYMEMO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-uglymemo
