# $NetBSD: buildlink3.mk,v 1.7 2025/08/13 11:07:25 pho Exp $

BUILDLINK_TREE+=	hs-filepath-bytestring

.if !defined(HS_FILEPATH_BYTESTRING_BUILDLINK3_MK)
HS_FILEPATH_BYTESTRING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-filepath-bytestring+=	hs-filepath-bytestring>=1.5.2
BUILDLINK_ABI_DEPENDS.hs-filepath-bytestring+=	hs-filepath-bytestring>=1.5.2.0.2nb3
BUILDLINK_PKGSRCDIR.hs-filepath-bytestring?=	../../sysutils/hs-filepath-bytestring
.endif	# HS_FILEPATH_BYTESTRING_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-filepath-bytestring
