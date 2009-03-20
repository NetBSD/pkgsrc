# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:04 joerg Exp $

BUILDLINK_TREE+=	cross-binutils

.if !defined(CROSS_BINUTILS_BUILDLINK3_MK)
CROSS_BINUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cross-binutils+=	cross-binutils>=2.17.0.0
BUILDLINK_PKGSRCDIR.cross-binutils?=	../../cross/binutils
.endif # CROSS_BINUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-cross-binutils
