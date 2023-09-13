# $NetBSD: buildlink3.mk,v 1.2 2023/09/13 00:36:33 gutteridge Exp $

BUILDLINK_TREE+=	trusted-firmware-a-rk3328

.if !defined(TRUSTED_FIRMWARE_A_RK3328_BUILDLINK3_MK)
TRUSTED_FIRMWARE_A_RK3328_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.trusted-firmware-a-rk3328+=	trusted-firmware-a-rk3328>=2.6
BUILDLINK_PKGSRCDIR.trusted-firmware-a-rk3328?=		../../sysutils/trusted-firmware-a-rk3328
BUILDLINK_DEPMETHOD.trusted-firmware-a-rk3328?=		build
.endif	# TRUSTED_FIRMWARE_A_RK3328_BUILDLINK3_MK

BUILDLINK_TREE+=	-trusted-firmware-a-rk3328
