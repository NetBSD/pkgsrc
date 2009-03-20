# $NetBSD: buildlink3.mk,v 1.13 2009/03/20 19:24:03 joerg Exp $

BUILDLINK_TREE+=	libwpd

.if !defined(LIBWPD_BUILDLINK3_MK)
LIBWPD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwpd+=	libwpd>=0.8.1nb1
BUILDLINK_ABI_DEPENDS.libwpd?=	libwpd>=0.8.9nb4
BUILDLINK_PKGSRCDIR.libwpd?=	../../converters/libwpd

.include "../../devel/libgsf/buildlink3.mk"
.endif # LIBWPD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwpd
