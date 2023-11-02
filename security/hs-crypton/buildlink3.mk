# $NetBSD: buildlink3.mk,v 1.2 2023/11/02 06:37:20 pho Exp $

BUILDLINK_TREE+=	hs-crypton

.if !defined(HS_CRYPTON_BUILDLINK3_MK)
HS_CRYPTON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-crypton+=	hs-crypton>=0.33
BUILDLINK_ABI_DEPENDS.hs-crypton+=	hs-crypton>=0.33nb1
BUILDLINK_PKGSRCDIR.hs-crypton?=	../../security/hs-crypton

.include "../../devel/hs-basement/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.endif	# HS_CRYPTON_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-crypton
