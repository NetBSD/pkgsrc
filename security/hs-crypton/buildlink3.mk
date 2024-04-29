# $NetBSD: buildlink3.mk,v 1.3 2024/04/29 09:35:01 pho Exp $

BUILDLINK_TREE+=	hs-crypton

.if !defined(HS_CRYPTON_BUILDLINK3_MK)
HS_CRYPTON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-crypton+=	hs-crypton>=1.0.0
BUILDLINK_ABI_DEPENDS.hs-crypton+=	hs-crypton>=1.0.0
BUILDLINK_PKGSRCDIR.hs-crypton?=	../../security/hs-crypton

.include "../../devel/hs-basement/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.endif	# HS_CRYPTON_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-crypton
