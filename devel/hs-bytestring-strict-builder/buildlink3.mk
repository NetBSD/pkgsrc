# $NetBSD: buildlink3.mk,v 1.2 2023/11/02 06:36:21 pho Exp $

BUILDLINK_TREE+=	hs-bytestring-strict-builder

.if !defined(HS_BYTESTRING_STRICT_BUILDER_BUILDLINK3_MK)
HS_BYTESTRING_STRICT_BUILDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bytestring-strict-builder+=	hs-bytestring-strict-builder>=0.4.5
BUILDLINK_ABI_DEPENDS.hs-bytestring-strict-builder+=	hs-bytestring-strict-builder>=0.4.5.7nb1
BUILDLINK_PKGSRCDIR.hs-bytestring-strict-builder?=	../../devel/hs-bytestring-strict-builder
.endif	# HS_BYTESTRING_STRICT_BUILDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bytestring-strict-builder
