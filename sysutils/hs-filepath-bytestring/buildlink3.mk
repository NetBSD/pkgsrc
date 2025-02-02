# $NetBSD: buildlink3.mk,v 1.4 2025/02/02 02:59:31 pho Exp $

BUILDLINK_TREE+=	hs-filepath-bytestring

.if !defined(HS_FILEPATH_BYTESTRING_BUILDLINK3_MK)
HS_FILEPATH_BYTESTRING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-filepath-bytestring+=	hs-filepath-bytestring>=1.5.2
BUILDLINK_ABI_DEPENDS.hs-filepath-bytestring+=	hs-filepath-bytestring>=1.5.2.0.2
BUILDLINK_PKGSRCDIR.hs-filepath-bytestring?=	../../sysutils/hs-filepath-bytestring
.endif	# HS_FILEPATH_BYTESTRING_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-filepath-bytestring
