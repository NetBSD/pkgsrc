# $NetBSD: buildlink3.mk,v 1.25 2018/01/07 13:04:00 rillig Exp $

BUILDLINK_TREE+=	binutils

.if !defined(BINUTILS_BUILDLINK3_MK)
BINUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.binutils+=	binutils>=2.22
BUILDLINK_PKGSRCDIR.binutils?=		../../devel/binutils
BUILDLINK_DEPMETHOD.binutils?=		build
.endif # BINUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-binutils
