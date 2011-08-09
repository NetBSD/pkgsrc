# $NetBSD: buildlink3.mk,v 1.11 2011/08/09 20:53:15 adam Exp $

BUILDLINK_TREE+=	libdvdread

.if !defined(LIBDVDREAD_BUILDLINK3_MK)
LIBDVDREAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdvdread+=	libdvdread>=4.1.3nb1
BUILDLINK_ABI_DEPENDS.libdvdread+=	libdvdread>=4.1.3nb1
BUILDLINK_PKGSRCDIR.libdvdread?=	../../multimedia/libdvdread
.endif # LIBDVDREAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdvdread
