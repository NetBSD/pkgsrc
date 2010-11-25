# $NetBSD: buildlink3.mk,v 1.14 2010/11/25 10:27:49 wiz Exp $

BUILDLINK_TREE+=	libwpd

.if !defined(LIBWPD_BUILDLINK3_MK)
LIBWPD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwpd+=	libwpd>=0.9.0
BUILDLINK_PKGSRCDIR.libwpd?=	../../converters/libwpd

.include "../../devel/libgsf/buildlink3.mk"
.endif # LIBWPD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwpd
