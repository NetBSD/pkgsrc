# $NetBSD: buildlink3.mk,v 1.1 2026/06/01 02:33:05 rxg Exp $

BUILDLINK_TREE+=	trusted-firmware-a-imx8mq

.if !defined(TRUSTED_FIRMWARE_A_IMX8MQ_BUILDLINK3_MK)
TRUSTED_FIRMWARE_A_IMX8MQ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.trusted-firmware-a-imx8mq+=	trusted-firmware-a-imx8mq>=2.6
BUILDLINK_PKGSRCDIR.trusted-firmware-a-imx8mq?=		../../sysutils/trusted-firmware-a-imx8mq
BUILDLINK_DEPMETHOD.trusted-firmware-a-imx8mq?=		build
.endif	# TRUSTED_FIRMWARE_A_IMX8MQ_BUILDLINK3_MK

BUILDLINK_TREE+=	-trusted-firmware-a-imx8mq
