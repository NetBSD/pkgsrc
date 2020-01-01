# $NetBSD: buildlink3.mk,v 1.1 2020/01/01 02:08:38 pho Exp $

BUILDLINK_TREE+=	hs-uuid-types

.if !defined(HS_UUID_TYPES_BUILDLINK3_MK)
HS_UUID_TYPES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-uuid-types+=	hs-uuid-types>=1.0.3
BUILDLINK_ABI_DEPENDS.hs-uuid-types+=	hs-uuid-types>=1.0.3
BUILDLINK_PKGSRCDIR.hs-uuid-types?=	../../devel/hs-uuid-types

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.endif	# HS_UUID_TYPES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-uuid-types
