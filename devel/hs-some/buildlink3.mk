# $NetBSD: buildlink3.mk,v 1.9 2025/02/02 13:05:23 pho Exp $

BUILDLINK_TREE+=	hs-some

.if !defined(HS_SOME_BUILDLINK3_MK)
HS_SOME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-some+=	hs-some>=1.0.6
BUILDLINK_ABI_DEPENDS.hs-some+=	hs-some>=1.0.6nb3
BUILDLINK_PKGSRCDIR.hs-some?=	../../devel/hs-some

.include "../../devel/hs-base-orphans/buildlink3.mk"
.endif	# HS_SOME_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-some
