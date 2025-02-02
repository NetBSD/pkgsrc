# $NetBSD: buildlink3.mk,v 1.4 2025/02/02 13:04:52 pho Exp $

BUILDLINK_TREE+=	hs-sandi

.if !defined(HS_SANDI_BUILDLINK3_MK)
HS_SANDI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-sandi+=	hs-sandi>=0.5
BUILDLINK_ABI_DEPENDS.hs-sandi+=	hs-sandi>=0.5nb3
BUILDLINK_PKGSRCDIR.hs-sandi?=		../../converters/hs-sandi

.include "../../devel/hs-conduit/buildlink3.mk"
.endif	# HS_SANDI_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-sandi
