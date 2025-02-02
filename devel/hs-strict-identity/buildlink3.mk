# $NetBSD: buildlink3.mk,v 1.3 2025/02/02 13:05:25 pho Exp $

BUILDLINK_TREE+=	hs-strict-identity

.if !defined(HS_STRICT_IDENTITY_BUILDLINK3_MK)
HS_STRICT_IDENTITY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-strict-identity+=	hs-strict-identity>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-strict-identity+=	hs-strict-identity>=0.1.0.0nb2
BUILDLINK_PKGSRCDIR.hs-strict-identity?=	../../devel/hs-strict-identity
.endif	# HS_STRICT_IDENTITY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-strict-identity
