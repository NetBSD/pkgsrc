# $NetBSD: buildlink3.mk,v 1.23 2009/03/20 19:24:10 joerg Exp $

BUILDLINK_TREE+=	binutils

.if !defined(BINUTILS_BUILDLINK3_MK)
BINUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.binutils+=	binutils>=2.17
BUILDLINK_PKGSRCDIR.binutils?=	../../devel/binutils
BUILDLINK_DEPMETHOD.binutils?=	build
.endif # BINUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-binutils
