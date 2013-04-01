# $NetBSD: buildlink3.mk,v 1.1.1.1 2013/04/01 21:02:02 jmcneill Exp $

BUILDLINK_TREE+=	raspberrypi-userland

.if !defined(RASPBERRYPI_USERLAND_BUILDLINK3_MK)
RASPBERRYPI_USERLAND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.raspberrypi-userland+=	raspberrypi-userland>=20130128
BUILDLINK_PKGSRCDIR.raspberrypi-userland?=	../../misc/raspberrypi-userland
.endif	# RASPBERRYPI_USERLAND_BUILDLINK3_MK

BUILDLINK_TREE+=	-raspberrypi-userland
