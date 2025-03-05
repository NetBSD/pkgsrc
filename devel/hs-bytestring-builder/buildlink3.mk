# $NetBSD: buildlink3.mk,v 1.12 2025/03/05 03:39:05 pho Exp $

BUILDLINK_TREE+=	hs-bytestring-builder

.if !defined(HS_BYTESTRING_BUILDER_BUILDLINK3_MK)
HS_BYTESTRING_BUILDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bytestring-builder+=	hs-bytestring-builder>=0.10.8
BUILDLINK_ABI_DEPENDS.hs-bytestring-builder+=	hs-bytestring-builder>=0.10.8.2.0nb10
BUILDLINK_PKGSRCDIR.hs-bytestring-builder?=	../../devel/hs-bytestring-builder
.endif	# HS_BYTESTRING_BUILDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bytestring-builder
