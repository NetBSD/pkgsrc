# $NetBSD: buildlink3.mk,v 1.8 2023/08/14 05:24:29 wiz Exp $

BUILDLINK_TREE+=	gpsd

.if !defined(GPSD_BUILDLINK3_MK)
GPSD_BUILDLINK3_MK:=

# 3.19 changed structures and is thus an ABI break.
BUILDLINK_API_DEPENDS.gpsd+=	gpsd>=3.19
BUILDLINK_ABI_DEPENDS.gpsd+=	gpsd>=3.25nb2
BUILDLINK_PKGSRCDIR.gpsd?=	../../geography/gpsd
.endif # GPSD_BUILDLINK3_MK

BUILDLINK_TREE+=	-gpsd
