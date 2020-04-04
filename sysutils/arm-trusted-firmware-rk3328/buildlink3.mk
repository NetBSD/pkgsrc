# $NetBSD: buildlink3.mk,v 1.1 2020/04/04 06:21:54 mrg Exp $

BUILDLINK_DEPMETHOD.arm-trusted-firmware-rk3328?=	build

BUILDLINK_TREE+=	arm-trusted-firmware-rk3328

.if !defined(ARM_TRUSTED_FIRMWARE_RK3328_BUILDLINK3_MK)
ARM_TRUSTED_FIRMWARE_RK3328_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.arm-trusted-firmware-rk3328+=	arm-trusted-firmware-rk3328>2.0
BUILDLINK_PKGSRCDIR.arm-trusted-firmware-rk3328?=	../../sysutils/arm-trusted-firmware-rk3328
.endif	# ARM_TRUSTED_FIRMWARE_RK3328_BUILDLINK3_MK

BUILDLINK_TREE+=	-arm-trusted-firmware-rk3328

