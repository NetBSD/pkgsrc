# $NetBSD: buildlink3.mk,v 1.12 2020/01/02 09:31:47 pho Exp $

BUILDLINK_TREE+=	hs-vault

.if !defined(HS_VAULT_BUILDLINK3_MK)
HS_VAULT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vault+=	hs-vault>=0.3.1
BUILDLINK_ABI_DEPENDS.hs-vault+=	hs-vault>=0.3.1.3
BUILDLINK_PKGSRCDIR.hs-vault?=		../../devel/hs-vault

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_VAULT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vault
