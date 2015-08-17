# $NetBSD: buildlink3.mk,v 1.9 2015/08/17 17:11:19 wiz Exp $

BUILDLINK_TREE+=	libggiwmh

.if !defined(LIBGGIWMH_BUILDLINK3_MK)
LIBGGIWMH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libggiwmh+=	libggiwmh>=0.2.0
BUILDLINK_ABI_DEPENDS.libggiwmh+=	libggiwmh>=0.3.2nb1
BUILDLINK_PKGSRCDIR.libggiwmh?=	../../graphics/libggiwmh

.include "../../graphics/libggi/buildlink3.mk"
.endif # LIBGGIWMH_BUILDLINK3_MK

BUILDLINK_TREE+=	-libggiwmh
