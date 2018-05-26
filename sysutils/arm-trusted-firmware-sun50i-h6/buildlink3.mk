# $NetBSD: buildlink3.mk,v 1.1 2018/05/26 17:51:33 jmcneill Exp $

BUILDLINK_DEPMETHOD.arm-trusted-firmware-sun50i-h6?=	build

BUILDLINK_TREE+=	arm-trusted-firmware-sun50i-h6

.if !defined(ARM_TRUSTED_FIRMWARE_SUN50I_H6_BUILDLINK3_MK)
ARM_TRUSTED_FIRMWARE_SUN50I_H6_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.arm-trusted-firmware-sun50i-h6+=	arm-trusted-firmware-sun50i-h6>=20180207
BUILDLINK_PKGSRCDIR.arm-trusted-firmware-sun50i-h6?=	../../sysutils/arm-trusted-firmware-sun50i-h6
.endif	# ARM_TRUSTED_FIRMWARE_SUN50I_H6_BUILDLINK3_MK

BUILDLINK_TREE+=	-arm-trusted-firmware-sun50i-h6
