# $NetBSD: buildlink3.mk,v 1.24 2025/09/27 09:57:09 wiz Exp $

BUILDLINK_TREE+=	librevenge

.if !defined(LIBREVENGE_BUILDLINK3_MK)
LIBREVENGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librevenge+=	librevenge>=0.0.1
BUILDLINK_ABI_DEPENDS.librevenge+=	librevenge>=0.0.5nb3
BUILDLINK_PKGSRCDIR.librevenge?=	../../converters/librevenge

.include "../../devel/boost-libs/buildlink3.mk"
.endif	# LIBREVENGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-librevenge
