# $NetBSD: buildlink3.mk,v 1.26 2022/06/28 11:31:40 wiz Exp $

BUILDLINK_TREE+=	binutils

.if !defined(BINUTILS_BUILDLINK3_MK)
BINUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.binutils+=	binutils>=2.22
BUILDLINK_ABI_DEPENDS.binutils?=		binutils>=2.38nb1
BUILDLINK_PKGSRCDIR.binutils?=		../../devel/binutils
BUILDLINK_DEPMETHOD.binutils?=		build
.endif # BINUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-binutils
