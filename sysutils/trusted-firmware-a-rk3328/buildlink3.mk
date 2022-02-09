# $NetBSD: buildlink3.mk,v 1.1 2022/02/09 01:57:57 mrg Exp $

BUILDLINK_DEPMETHOD.trusted-firmware-a-rk3328?=	build

BUILDLINK_TREE+=	trusted-firmware-a-rk3328

.if !defined(TRUSTED_FIRMWARE_A_RK3328_BUILDLINK3_MK)
TRUSTED_FIRMWARE_A_RK3328_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.trusted-firmware-a-rk3328+=	trusted-firmware-a-rk3328>=2.6
BUILDLINK_PKGSRCDIR.trusted-firmware-a-rk3328?=	../../sysutils/trusted-firmware-a-rk3328
.endif	# TRUSTED_FIRMWARE_A_RK3328_BUILDLINK3_MK

BUILDLINK_TREE+=	-trusted-firmware-a-rk3328

