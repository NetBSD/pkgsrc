# $NetBSD: buildlink3.mk,v 1.1 2014/07/22 10:47:52 wiz Exp $

BUILDLINK_TREE+=	librevenge

.if !defined(LIBREVENGE_BUILDLINK3_MK)
LIBREVENGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librevenge+=	librevenge>=0.0.1
BUILDLINK_PKGSRCDIR.librevenge?=	../../converters/librevenge

.endif	# LIBREVENGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-librevenge
