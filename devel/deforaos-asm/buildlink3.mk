# $NetBSD: buildlink3.mk,v 1.1 2016/02/20 03:14:46 khorben Exp $
#

BUILDLINK_TREE+=	deforaos-asm

.if !defined(DEFORAOS_ASM_BUILDLINK3_MK)
DEFORAOS_ASM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-asm+=	deforaos-asm>=0.2.3
BUILDLINK_ABI_DEPENDS.deforaos-asm?=	deforaos-asm>=0.2.3
BUILDLINK_PKGSRCDIR.deforaos-asm?=	../../devel/deforaos-asm

.include "../../devel/deforaos-cpp/buildlink3.mk"
.endif	# DEFORAOS_ASM_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-asm
