# $NetBSD: buildlink3.mk,v 1.36 2023/01/22 16:28:14 ryoon Exp $

BUILDLINK_TREE+=	libwpd

.if !defined(LIBWPD_BUILDLINK3_MK)
LIBWPD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwpd+=	libwpd>=0.9.5
BUILDLINK_ABI_DEPENDS.libwpd+=	libwpd>=0.10.3nb6
BUILDLINK_PKGSRCDIR.libwpd?=	../../converters/libwpd

.include "../../converters/librevenge/buildlink3.mk"
.endif # LIBWPD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwpd
