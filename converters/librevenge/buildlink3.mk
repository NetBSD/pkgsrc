# $NetBSD: buildlink3.mk,v 1.6 2017/08/24 20:02:57 adam Exp $

BUILDLINK_TREE+=	librevenge

.if !defined(LIBREVENGE_BUILDLINK3_MK)
LIBREVENGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librevenge+=	librevenge>=0.0.1
BUILDLINK_ABI_DEPENDS.librevenge+=	librevenge>=0.0.4nb4
BUILDLINK_PKGSRCDIR.librevenge?=	../../converters/librevenge

.include "../../devel/boost-libs/buildlink3.mk"
.endif	# LIBREVENGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-librevenge
