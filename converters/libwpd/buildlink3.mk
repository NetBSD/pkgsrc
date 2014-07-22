# $NetBSD: buildlink3.mk,v 1.18 2014/07/22 10:55:14 wiz Exp $

BUILDLINK_TREE+=	libwpd

.if !defined(LIBWPD_BUILDLINK3_MK)
LIBWPD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwpd+=	libwpd>=0.9.5
BUILDLINK_ABI_DEPENDS.libwpd+=	libwpd>=0.10.0
BUILDLINK_PKGSRCDIR.libwpd?=	../../converters/libwpd

.include "../../converters/librevenge/buildlink3.mk"
.endif # LIBWPD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwpd
