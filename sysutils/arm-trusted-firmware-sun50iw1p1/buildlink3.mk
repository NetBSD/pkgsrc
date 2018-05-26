# $NetBSD: buildlink3.mk,v 1.2 2018/05/26 17:29:44 jmcneill Exp $

BUILDLINK_DEPMETHOD.arm-trusted-firmware-sun50iw1p1?=	build

BUILDLINK_TREE+=	arm-trusted-firmware-sun50iw1p1

.if !defined(ARM_TRUSTED_FIRMWARE_SUN50IW1P1_BUILDLINK3_MK)
ARM_TRUSTED_FIRMWARE_SUN50IW1P1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.arm-trusted-firmware-sun50iw1p1+=	arm-trusted-firmware-sun50iw1p1>=20180210
BUILDLINK_PKGSRCDIR.arm-trusted-firmware-sun50iw1p1?=	../../sysutils/arm-trusted-firmware-sun50iw1p1
.endif	# ARM_TRUSTED_FIRMWARE_SUN50IW1P1_BUILDLINK3_MK

BUILDLINK_TREE+=	-arm-trusted-firmware-sun50iw1p1
