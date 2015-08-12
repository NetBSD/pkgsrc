# $NetBSD: buildlink3.mk,v 1.1 2015/08/12 00:29:14 ryoon Exp $

BUILDLINK_TREE+=	libwps

.if !defined(LIBWPS_BUILDLINK3_MK)
LIBWPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwps+=	libwps>=0.2.0
BUILDLINK_ABI_DEPENDS.libwps?=	libwps>=0.3.0
BUILDLINK_PKGSRCDIR.libwps?=	../../converters/libwps03

.include "../../converters/librevenge/buildlink3.mk"
.include "../../converters/libwpd/buildlink3.mk"
.endif	# LIBWPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwps
