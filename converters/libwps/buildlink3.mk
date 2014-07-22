# $NetBSD: buildlink3.mk,v 1.2 2014/07/22 10:53:30 wiz Exp $

BUILDLINK_TREE+=	libwps

.if !defined(LIBWPS_BUILDLINK3_MK)
LIBWPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwps+=	libwps>=0.2.0
BUILDLINK_ABI_DEPENDS.libwps?=	libwps>=0.2.4nb1
BUILDLINK_PKGSRCDIR.libwps?=	../../converters/libwps

.include "../../converters/libwpd/buildlink3.mk"
.endif	# LIBWPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwps
