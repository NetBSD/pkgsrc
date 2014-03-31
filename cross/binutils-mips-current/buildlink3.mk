# $NetBSD: buildlink3.mk,v 1.1 2014/03/31 09:46:57 martin Exp $

BUILDLINK_TREE+=	binutils-mips

.if !defined(CROSS_BINUTILS_BUILDLINK3_MK)
CROSS_BINUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.binutils-mips+=	binutils-mips>=2.23.91.0
BUILDLINK_PKGSRCDIR.binutils-mips?=	../../cross/binutils-mips-current
.endif # CROSS_BINUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-binutils-mips
