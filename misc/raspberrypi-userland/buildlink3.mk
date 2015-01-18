# $NetBSD: buildlink3.mk,v 1.2 2015/01/18 21:41:36 jmcneill Exp $

BUILDLINK_TREE+=	raspberrypi-userland

.if !defined(RASPBERRYPI_USERLAND_BUILDLINK3_MK)
RASPBERRYPI_USERLAND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.raspberrypi-userland+=	raspberrypi-userland>=20130128nb1
BUILDLINK_PKGSRCDIR.raspberrypi-userland?=	../../misc/raspberrypi-userland
.endif	# RASPBERRYPI_USERLAND_BUILDLINK3_MK

BUILDLINK_TREE+=	-raspberrypi-userland
