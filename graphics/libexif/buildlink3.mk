# $NetBSD: buildlink3.mk,v 1.14 2009/03/20 19:24:41 joerg Exp $

BUILDLINK_TREE+=	libexif

.if !defined(LIBEXIF_BUILDLINK3_MK)
LIBEXIF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libexif+=	libexif>=0.6.11
BUILDLINK_ABI_DEPENDS.libexif+=	libexif>=0.6.13nb1
BUILDLINK_PKGSRCDIR.libexif?=	../../graphics/libexif

.include "../../devel/gettext-lib/buildlink3.mk"
.endif # LIBEXIF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libexif
