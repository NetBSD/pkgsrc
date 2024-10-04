# $NetBSD: buildlink3.mk,v 1.22 2024/10/04 03:49:17 ryoon Exp $

BUILDLINK_TREE+=	librevenge

.if !defined(LIBREVENGE_BUILDLINK3_MK)
LIBREVENGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librevenge+=	librevenge>=0.0.1
BUILDLINK_ABI_DEPENDS.librevenge+=	librevenge>=0.0.5nb1
BUILDLINK_PKGSRCDIR.librevenge?=	../../converters/librevenge

.include "../../devel/boost-libs/buildlink3.mk"
.endif	# LIBREVENGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-librevenge
