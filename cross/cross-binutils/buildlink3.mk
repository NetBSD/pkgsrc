# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:31:14 wiz Exp $

BUILDLINK_TREE+=	cross-binutils

.if !defined(CROSS_BINUTILS_BUILDLINK3_MK)
CROSS_BINUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cross-binutils+=	cross-binutils>=2.17.0.0
BUILDLINK_ABI_DEPENDS.cross-binutils?=	cross-binutils>=2.17.0.0nb6
BUILDLINK_PKGSRCDIR.cross-binutils?=	../../cross/cross-binutils
.endif # CROSS_BINUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-cross-binutils
