# $NetBSD: buildlink3.mk,v 1.1 2010/11/26 14:04:51 adam Exp $

BUILDLINK_TREE+=	libwps

.if !defined(LIBWPS_BUILDLINK3_MK)
LIBWPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwps+=	libwps>=0.2.0
BUILDLINK_PKGSRCDIR.libwps?=	../../converters/libwps

.include "../../converters/libwpd/buildlink3.mk"
.endif	# LIBWPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwps
