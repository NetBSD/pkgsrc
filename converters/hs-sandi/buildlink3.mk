# $NetBSD: buildlink3.mk,v 1.2 2023/11/02 06:36:13 pho Exp $

BUILDLINK_TREE+=	hs-sandi

.if !defined(HS_SANDI_BUILDLINK3_MK)
HS_SANDI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-sandi+=	hs-sandi>=0.5
BUILDLINK_ABI_DEPENDS.hs-sandi+=	hs-sandi>=0.5nb1
BUILDLINK_PKGSRCDIR.hs-sandi?=		../../converters/hs-sandi

.include "../../devel/hs-conduit/buildlink3.mk"
.endif	# HS_SANDI_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-sandi
