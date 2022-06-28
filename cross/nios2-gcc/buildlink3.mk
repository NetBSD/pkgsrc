# $NetBSD: buildlink3.mk,v 1.3 2022/06/28 11:31:16 wiz Exp $

BUILDLINK_TREE+=	nios2-gcc

.if !defined(NIOS2_GCC_BUILDLINK3_MK)
NIOS2_GCC_BUILDLINK3_MK:=


BUILDLINK_API_DEPENDS.nios2-gcc+=	nios2-gcc>=4.7.3
BUILDLINK_ABI_DEPENDS.nios2-gcc?=		nios2-gcc>=4.7.3nb10
BUILDLINK_PKGSRCDIR.nios2-gcc?=		../../cross/nios2-gcc
BUILDLINK_FNAME_TRANSFORM.nios2-gcc+=	-e "s,${NIOS2_TARGET}/lib,lib/,g"
.endif # NIOS2-GCC_BUILDLINK3_MK

BUILDLINK_TREE+=	-nios2-gcc
