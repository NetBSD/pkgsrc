# $NetBSD: buildlink3.mk,v 1.3 2015/01/29 23:38:28 jmcneill Exp $

BUILDLINK_TREE+=	raspberrypi-userland

.if !defined(RASPBERRYPI_USERLAND_BUILDLINK3_MK)
RASPBERRYPI_USERLAND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.raspberrypi-userland+=	raspberrypi-userland>=20150118nb1
BUILDLINK_PKGSRCDIR.raspberrypi-userland?=	../../misc/raspberrypi-userland
.endif	# RASPBERRYPI_USERLAND_BUILDLINK3_MK

BUILDLINK_TREE+=	-raspberrypi-userland
