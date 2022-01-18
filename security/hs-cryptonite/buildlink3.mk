# $NetBSD: buildlink3.mk,v 1.4 2022/01/18 02:48:20 pho Exp $

BUILDLINK_TREE+=	hs-cryptonite

.if !defined(HS_CRYPTONITE_BUILDLINK3_MK)
HS_CRYPTONITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cryptonite+=	hs-cryptonite>=0.28
BUILDLINK_ABI_DEPENDS.hs-cryptonite+=	hs-cryptonite>=0.28nb2
BUILDLINK_PKGSRCDIR.hs-cryptonite?=	../../security/hs-cryptonite

.include "../../devel/hs-basement/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.endif	# HS_CRYPTONITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cryptonite
