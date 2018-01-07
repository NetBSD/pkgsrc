# $NetBSD: buildlink3.mk,v 1.11 2018/01/07 13:04:24 rillig Exp $

BUILDLINK_TREE+=	libdvdnav

.if !defined(LIBDVDNAV_BUILDLINK3_MK)
LIBDVDNAV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdvdnav+=	libdvdnav>=4.1.3
BUILDLINK_ABI_DEPENDS.libdvdnav+=	libdvdnav>=5.0
BUILDLINK_PKGSRCDIR.libdvdnav?=		../../multimedia/libdvdnav

.include "../../multimedia/libdvdread/buildlink3.mk"
.endif # LIBDVDNAV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdvdnav
