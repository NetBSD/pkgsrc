# $NetBSD: buildlink3.mk,v 1.8 2015/01/31 21:24:11 adam Exp $

BUILDLINK_TREE+=	libdvdcss

.if !defined(LIBDVDCSS_BUILDLINK3_MK)
LIBDVDCSS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdvdcss+=	libdvdcss>=1.3.99
BUILDLINK_ABI_DEPENDS.libdvdcss+=	libdvdcss>=1.3.99
BUILDLINK_PKGSRCDIR.libdvdcss?=	../../multimedia/libdvdcss
.endif # LIBDVDCSS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdvdcss
