# $NetBSD: buildlink3.mk,v 1.5 2023/11/02 06:37:03 pho Exp $

BUILDLINK_TREE+=	hs-uuid

.if !defined(HS_UUID_BUILDLINK3_MK)
HS_UUID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-uuid+=	hs-uuid>=1.3.15
BUILDLINK_ABI_DEPENDS.hs-uuid+=	hs-uuid>=1.3.15nb4
BUILDLINK_PKGSRCDIR.hs-uuid?=	../../devel/hs-uuid

.include "../../security/hs-cryptohash-md5/buildlink3.mk"
.include "../../security/hs-cryptohash-sha1/buildlink3.mk"
.include "../../security/hs-entropy/buildlink3.mk"
.include "../../net/hs-network-info/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-uuid-types/buildlink3.mk"
.endif	# HS_UUID_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-uuid
