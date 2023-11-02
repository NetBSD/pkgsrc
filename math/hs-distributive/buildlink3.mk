# $NetBSD: buildlink3.mk,v 1.13 2023/11/02 06:37:12 pho Exp $

BUILDLINK_TREE+=	hs-distributive

.if !defined(HS_DISTRIBUTIVE_BUILDLINK3_MK)
HS_DISTRIBUTIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-distributive+=	hs-distributive>=0.6.2
BUILDLINK_ABI_DEPENDS.hs-distributive+=	hs-distributive>=0.6.2.1nb7
BUILDLINK_PKGSRCDIR.hs-distributive?=	../../math/hs-distributive

.include "../../devel/hs-base-orphans/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.endif	# HS_DISTRIBUTIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-distributive
