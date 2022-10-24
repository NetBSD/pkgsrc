# $NetBSD: buildlink3.mk,v 1.1 2022/10/24 07:46:20 fcambus Exp $

BUILDLINK_TREE+=	lzlib

.if !defined(LZLIB_BUILDLINK3_MK)
LZLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lzlib+=	lzlib>=1.11
BUILDLINK_PKGSRCDIR.lzlib?=	../../archivers/lzlib
.endif	# LZLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-lzlib
