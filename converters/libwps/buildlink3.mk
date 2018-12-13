# $NetBSD: buildlink3.mk,v 1.13 2018/12/13 19:51:33 adam Exp $

BUILDLINK_TREE+=	libwps

.if !defined(LIBWPS_BUILDLINK3_MK)
LIBWPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwps+=	libwps>=0.4.0
BUILDLINK_ABI_DEPENDS.libwps?=	libwps>=0.4.3nb8
BUILDLINK_PKGSRCDIR.libwps?=	../../converters/libwps

.include "../../converters/librevenge/buildlink3.mk"
.include "../../converters/libwpd/buildlink3.mk"
.endif	# LIBWPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwps
