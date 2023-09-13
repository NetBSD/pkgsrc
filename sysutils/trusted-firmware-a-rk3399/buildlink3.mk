# $NetBSD: buildlink3.mk,v 1.2 2023/09/13 00:37:46 gutteridge Exp $

BUILDLINK_TREE+=	trusted-firmware-a-rk3399

.if !defined(TRUSTED_FIRMWARE_A_RK3399_BUILDLINK3_MK)
TRUSTED_FIRMWARE_A_RK3399_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.trusted-firmware-a-rk3399+=	trusted-firmware-a-rk3399>=2.6
BUILDLINK_PKGSRCDIR.trusted-firmware-a-rk3399?=		../../sysutils/trusted-firmware-a-rk3399
BUILDLINK_DEPMETHOD.trusted-firmware-a-rk3399?=		build
.endif	# TRUSTED_FIRMWARE_A_RK3399_BUILDLINK3_MK

BUILDLINK_TREE+=	-trusted-firmware-a-rk3399
