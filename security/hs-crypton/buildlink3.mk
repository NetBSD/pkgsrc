# $NetBSD: buildlink3.mk,v 1.7 2025/03/05 03:39:49 pho Exp $

BUILDLINK_TREE+=	hs-crypton

.if !defined(HS_CRYPTON_BUILDLINK3_MK)
HS_CRYPTON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-crypton+=	hs-crypton>=1.0.1
BUILDLINK_ABI_DEPENDS.hs-crypton+=	hs-crypton>=1.0.1nb2
BUILDLINK_PKGSRCDIR.hs-crypton?=	../../security/hs-crypton

.include "../../devel/hs-basement/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.endif	# HS_CRYPTON_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-crypton
