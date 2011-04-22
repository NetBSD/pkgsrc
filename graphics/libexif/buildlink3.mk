# $NetBSD: buildlink3.mk,v 1.15 2011/04/22 13:41:57 obache Exp $

BUILDLINK_TREE+=	libexif

.if !defined(LIBEXIF_BUILDLINK3_MK)
LIBEXIF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libexif+=	libexif>=0.6.11
BUILDLINK_ABI_DEPENDS.libexif+=	libexif>=0.6.20nb1
BUILDLINK_PKGSRCDIR.libexif?=	../../graphics/libexif

.include "../../devel/gettext-lib/buildlink3.mk"
.endif # LIBEXIF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libexif
