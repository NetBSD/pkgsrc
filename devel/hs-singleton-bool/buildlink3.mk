# $NetBSD: buildlink3.mk,v 1.8 2025/02/02 13:05:23 pho Exp $

BUILDLINK_TREE+=	hs-singleton-bool

.if !defined(HS_SINGLETON_BOOL_BUILDLINK3_MK)
HS_SINGLETON_BOOL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-singleton-bool+=	hs-singleton-bool>=0.1.8
BUILDLINK_ABI_DEPENDS.hs-singleton-bool+=	hs-singleton-bool>=0.1.8nb1
BUILDLINK_PKGSRCDIR.hs-singleton-bool?=		../../devel/hs-singleton-bool

.include "../../devel/hs-boring/buildlink3.mk"
.include "../../devel/hs-dec/buildlink3.mk"
.include "../../devel/hs-some/buildlink3.mk"
.endif	# HS_SINGLETON_BOOL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-singleton-bool
