# $NetBSD: buildlink3.mk,v 1.7 2023/03/09 00:57:03 gdt Exp $

BUILDLINK_TREE+=	gpsd

.if !defined(GPSD_BUILDLINK3_MK)
GPSD_BUILDLINK3_MK:=

# 3.19 changed structures and is thus an ABI break.
BUILDLINK_API_DEPENDS.gpsd+=	gpsd>=3.19
BUILDLINK_ABI_DEPENDS.gpsd+=	gpsd>=3.25
BUILDLINK_PKGSRCDIR.gpsd?=	../../geography/gpsd
.endif # GPSD_BUILDLINK3_MK

BUILDLINK_TREE+=	-gpsd
