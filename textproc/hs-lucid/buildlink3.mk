# $NetBSD: buildlink3.mk,v 1.7 2022/02/26 03:58:28 pho Exp $

BUILDLINK_TREE+=	hs-lucid

.if !defined(HS_LUCID_BUILDLINK3_MK)
HS_LUCID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-lucid+=	hs-lucid>=2.11.0
BUILDLINK_ABI_DEPENDS.hs-lucid+=	hs-lucid>=2.11.0nb2
BUILDLINK_PKGSRCDIR.hs-lucid?=		../../textproc/hs-lucid

.include "../../devel/hs-blaze-builder/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-mmorph/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_LUCID_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-lucid
