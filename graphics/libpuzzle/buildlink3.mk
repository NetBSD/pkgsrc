# $NetBSD: buildlink3.mk,v 1.15 2015/11/18 14:19:46 ryoon Exp $

BUILDLINK_TREE+=	libpuzzle

.if !defined(LIBPUZZLE_BUILDLINK3_MK)
LIBPUZZLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpuzzle+=	libpuzzle>=0.9
BUILDLINK_ABI_DEPENDS.libpuzzle+=	libpuzzle>=0.11nb14
BUILDLINK_PKGSRCDIR.libpuzzle?=	../../graphics/libpuzzle

.include "../../graphics/gd/buildlink3.mk"
.endif # LIBPUZZLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpuzzle
