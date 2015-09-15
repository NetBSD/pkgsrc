# $NetBSD: buildlink3.mk,v 1.3 2015/09/15 14:12:15 joerg Exp $

BUILDLINK_TREE+=	libwps

.if !defined(LIBWPS_BUILDLINK3_MK)
LIBWPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwps+=	libwps>=0.2.0<0.4
BUILDLINK_ABI_DEPENDS.libwps?=	libwps>=0.3.1nb1<0.4
BUILDLINK_PKGSRCDIR.libwps?=	../../converters/libwps03

.include "../../converters/librevenge/buildlink3.mk"
.include "../../converters/libwpd/buildlink3.mk"
.endif	# LIBWPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwps
