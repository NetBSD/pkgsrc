# $NetBSD: buildlink3.mk,v 1.1 2020/03/30 16:34:14 riastradh Exp $

BUILDLINK_TREE+=	hs-bytestring-builder

.if !defined(HS_BYTESTRING_BUILDER_BUILDLINK3_MK)
HS_BYTESTRING_BUILDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bytestring-builder+=	hs-bytestring-builder>=0.10.8.2.0
BUILDLINK_ABI_DEPENDS.hs-bytestring-builder+=	hs-bytestring-builder>=0.10.8.2.0
BUILDLINK_PKGSRCDIR.hs-bytestring-builder?=	../../devel/hs-bytestring-builder
.endif	# HS_BYTESTRING_BUILDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bytestring-builder
