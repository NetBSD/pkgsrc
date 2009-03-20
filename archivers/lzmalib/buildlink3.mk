# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:23:51 joerg Exp $

BUILDLINK_TREE+=	lzmalib

.if !defined(LZMALIB_BUILDLINK3_MK)
LZMALIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lzmalib+=	lzmalib>=0.0.1
BUILDLINK_PKGSRCDIR.lzmalib?=	../../archivers/lzmalib
.endif # LZMALIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-lzmalib
