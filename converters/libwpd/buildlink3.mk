# $NetBSD: buildlink3.mk,v 1.16 2013/08/24 21:50:24 jaapb Exp $

BUILDLINK_TREE+=	libwpd

.if !defined(LIBWPD_BUILDLINK3_MK)
LIBWPD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwpd+=	libwpd>=0.9.5
BUILDLINK_PKGSRCDIR.libwpd?=	../../converters/libwpd

.endif # LIBWPD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwpd
