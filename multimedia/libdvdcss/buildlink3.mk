# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:25:03 joerg Exp $

BUILDLINK_TREE+=	libdvdcss

.if !defined(LIBDVDCSS_BUILDLINK3_MK)
LIBDVDCSS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdvdcss+=	libdvdcss>=1.2.4
BUILDLINK_ABI_DEPENDS.libdvdcss+=	libdvdcss>=1.2.8nb1
BUILDLINK_PKGSRCDIR.libdvdcss?=	../../multimedia/libdvdcss
.endif # LIBDVDCSS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdvdcss
