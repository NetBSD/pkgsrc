# $NetBSD: buildlink3.mk,v 1.7 2023/02/07 01:40:29 pho Exp $

BUILDLINK_TREE+=	hs-bytestring-builder

.if !defined(HS_BYTESTRING_BUILDER_BUILDLINK3_MK)
HS_BYTESTRING_BUILDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bytestring-builder+=	hs-bytestring-builder>=0.10.8
BUILDLINK_ABI_DEPENDS.hs-bytestring-builder+=	hs-bytestring-builder>=0.10.8.2.0nb5
BUILDLINK_PKGSRCDIR.hs-bytestring-builder?=	../../devel/hs-bytestring-builder
.endif	# HS_BYTESTRING_BUILDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bytestring-builder
