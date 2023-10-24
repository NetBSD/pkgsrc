# $NetBSD: buildlink3.mk,v 1.1 2023/10/24 08:19:49 pho Exp $

BUILDLINK_TREE+=	hs-filepath-bytestring

.if !defined(HS_FILEPATH_BYTESTRING_BUILDLINK3_MK)
HS_FILEPATH_BYTESTRING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-filepath-bytestring+=	hs-filepath-bytestring>=1.4.2
BUILDLINK_ABI_DEPENDS.hs-filepath-bytestring+=	hs-filepath-bytestring>=1.4.2.1.13
BUILDLINK_PKGSRCDIR.hs-filepath-bytestring?=	../../sysutils/hs-filepath-bytestring
.endif	# HS_FILEPATH_BYTESTRING_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-filepath-bytestring
