# $NetBSD: buildlink3.mk,v 1.1 2017/02/04 01:41:41 ryoon Exp $

BUILDLINK_TREE+=	libstaroffice

.if !defined(LIBSTAROFFICE_BUILDLINK3_MK)
LIBSTAROFFICE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libstaroffice+=	libstaroffice>=0.0.2
BUILDLINK_PKGSRCDIR.libstaroffice?=	../../converters/libstaroffice

.endif	# LIBSTAROFFICE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libstaroffice
