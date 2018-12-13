# $NetBSD: buildlink3.mk,v 1.27 2018/12/13 19:51:32 adam Exp $

BUILDLINK_TREE+=	libwpd

.if !defined(LIBWPD_BUILDLINK3_MK)
LIBWPD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwpd+=	libwpd>=0.9.5
BUILDLINK_ABI_DEPENDS.libwpd+=	libwpd>=0.10.1nb8
BUILDLINK_PKGSRCDIR.libwpd?=	../../converters/libwpd

.include "../../converters/librevenge/buildlink3.mk"
.endif # LIBWPD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwpd
