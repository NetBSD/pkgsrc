# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:31:14 wiz Exp $

BUILDLINK_TREE+=	binutils-mips

.if !defined(CROSS_BINUTILS_BUILDLINK3_MK)
CROSS_BINUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.binutils-mips+=	binutils-mips>=2.23.91.0
BUILDLINK_ABI_DEPENDS.binutils-mips?=	binutils-mips>=2.25nb3
BUILDLINK_PKGSRCDIR.binutils-mips?=	../../cross/binutils-mips-current
.endif # CROSS_BINUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-binutils-mips
