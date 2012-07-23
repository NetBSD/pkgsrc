# $NetBSD: buildlink3.mk,v 1.24 2012/07/23 12:24:34 jperkin Exp $

BUILDLINK_TREE+=	binutils

.if !defined(BINUTILS_BUILDLINK3_MK)
BINUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.binutils+=	binutils>=2.22
BUILDLINK_PKGSRCDIR.binutils?=	../../devel/binutils
BUILDLINK_DEPMETHOD.binutils?=	build
.endif # BINUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-binutils
