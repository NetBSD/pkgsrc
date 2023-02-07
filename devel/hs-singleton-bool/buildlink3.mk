# $NetBSD: buildlink3.mk,v 1.2 2023/02/07 01:40:49 pho Exp $

BUILDLINK_TREE+=	hs-singleton-bool

.if !defined(HS_SINGLETON_BOOL_BUILDLINK3_MK)
HS_SINGLETON_BOOL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-singleton-bool+=	hs-singleton-bool>=0.1.6
BUILDLINK_ABI_DEPENDS.hs-singleton-bool+=	hs-singleton-bool>=0.1.6nb1
BUILDLINK_PKGSRCDIR.hs-singleton-bool?=		../../devel/hs-singleton-bool

.include "../../devel/hs-boring/buildlink3.mk"
.include "../../devel/hs-dec/buildlink3.mk"
.include "../../devel/hs-some/buildlink3.mk"
.endif	# HS_SINGLETON_BOOL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-singleton-bool
