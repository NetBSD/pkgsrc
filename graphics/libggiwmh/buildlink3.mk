# $NetBSD: buildlink3.mk,v 1.8 2012/05/07 01:53:36 dholland Exp $

BUILDLINK_TREE+=	libggiwmh

.if !defined(LIBGGIWMH_BUILDLINK3_MK)
LIBGGIWMH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libggiwmh+=	libggiwmh>=0.2.0
BUILDLINK_ABI_DEPENDS.libggiwmh+=	libggiwmh>=0.2.1nb1
BUILDLINK_PKGSRCDIR.libggiwmh?=	../../graphics/libggiwmh

.include "../../graphics/libggi/buildlink3.mk"
.endif # LIBGGIWMH_BUILDLINK3_MK

BUILDLINK_TREE+=	-libggiwmh
