# $NetBSD: buildlink3.mk,v 1.26 2024/12/29 15:09:42 adam Exp $

BUILDLINK_TREE+=	libwps

.if !defined(LIBWPS_BUILDLINK3_MK)
LIBWPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwps+=	libwps>=0.4.0
BUILDLINK_ABI_DEPENDS.libwps+=	libwps>=0.4.12nb9
BUILDLINK_PKGSRCDIR.libwps?=	../../converters/libwps

.include "../../converters/librevenge/buildlink3.mk"
.include "../../converters/libwpd/buildlink3.mk"
.endif	# LIBWPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwps
