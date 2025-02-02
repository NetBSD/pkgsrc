# $NetBSD: buildlink3.mk,v 1.8 2025/02/02 13:05:29 pho Exp $

BUILDLINK_TREE+=	hs-uuid

.if !defined(HS_UUID_BUILDLINK3_MK)
HS_UUID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-uuid+=	hs-uuid>=1.3.16
BUILDLINK_ABI_DEPENDS.hs-uuid+=	hs-uuid>=1.3.16nb1
BUILDLINK_PKGSRCDIR.hs-uuid?=	../../devel/hs-uuid

.include "../../security/hs-cryptohash-md5/buildlink3.mk"
.include "../../security/hs-cryptohash-sha1/buildlink3.mk"
.include "../../security/hs-entropy/buildlink3.mk"
.include "../../net/hs-network-info/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-uuid-types/buildlink3.mk"
.endif	# HS_UUID_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-uuid
