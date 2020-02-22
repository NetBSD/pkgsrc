# $NetBSD: buildlink3.mk,v 1.3 2020/02/22 11:55:36 mrg Exp $

BUILDLINK_DEPMETHOD.arm-trusted-firmware-rk3399?=	build

BUILDLINK_TREE+=	arm-trusted-firmware-rk3399

.if !defined(ARM_TRUSTED_FIRMWARE_RK3399_BUILDLINK3_MK)
ARM_TRUSTED_FIRMWARE_RK3399_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.arm-trusted-firmware-rk3399+=	arm-trusted-firmware-rk3399>=2.2nb1
BUILDLINK_PKGSRCDIR.arm-trusted-firmware-rk3399?=	../../sysutils/arm-trusted-firmware-rk3399
.endif	# ARM_TRUSTED_FIRMWARE_RK3399_BUILDLINK3_MK

BUILDLINK_TREE+=	-arm-trusted-firmware-rk3399

