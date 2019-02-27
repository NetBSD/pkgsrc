# $NetBSD: buildlink3.mk,v 1.3 2019/02/27 06:23:39 martin Exp $

BUILDLINK_DEPMETHOD.arm-trusted-firmware-sun50i_a64?=	build

BUILDLINK_TREE+=	arm-trusted-firmware-sun50i_a64

.if !defined(ARM_TRUSTED_FIRMWARE_SUN50I_A64_BUILDLINK3_MK)
ARM_TRUSTED_FIRMWARE_SUN50I_A64_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.arm-trusted-firmware-sun50i_a64+=	arm-trusted-firmware-sun50i_a64>2.0
BUILDLINK_PKGSRCDIR.arm-trusted-firmware-sun50i_a64?=	../../sysutils/arm-trusted-firmware-sun50i_a64
.endif	# ARM_TRUSTED_FIRMWARE_SUN50I_A64_BUILDLINK3_MK

BUILDLINK_TREE+=	-arm-trusted-firmware-sun50i_a64

