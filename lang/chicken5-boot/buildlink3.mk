# $NetBSD: buildlink3.mk,v 1.2 2023/04/30 20:18:08 nikita Exp $

BUILDLINK_TREE+=	chicken5-boot

.if !defined(CHICKEN5_BOOT_BUILDLINK3_MK)
CHICKEN5_BOOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.chicken5-boot+=	chicken5-boot>=5.3.0
BUILDLINK_ABI_DEPENDS.chicken5-boot+=	chicken5-boot>=5.3.0
BUILDLINK_PKGSRCDIR.chicken5-boot?=	../../lang/chicken5-boot

BUILDLINK_FILES.chicken5-boot+=		libexec/chicken-bootstrap

.endif # CHICKEN5_BOOT_BUILDLINK3_MK

BUILDLINK_TREE+=	-chicken5-boot
