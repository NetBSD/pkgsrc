# $NetBSD: buildlink3.mk,v 1.3 2009/08/26 19:56:50 sno Exp $

BUILDLINK_TREE+=	libpuzzle

.if !defined(LIBPUZZLE_BUILDLINK3_MK)
LIBPUZZLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpuzzle+=	libpuzzle>=0.9
BUILDLINK_ABI_DEPENDS.libpuzzle?=	libpuzzle>=0.11nb1
BUILDLINK_PKGSRCDIR.libpuzzle?=	../../graphics/libpuzzle

.include "../../graphics/gd/buildlink3.mk"
.endif # LIBPUZZLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpuzzle
