# $NetBSD: buildlink3.mk,v 1.17 2020/05/06 14:04:06 adam Exp $

BUILDLINK_TREE+=	libmwaw

.if !defined(LIBMWAW_BUILDLINK3_MK)
LIBMWAW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmwaw+=	libmwaw>=0.2.0
BUILDLINK_ABI_DEPENDS.libmwaw?=	libmwaw>=0.3.16nb1
BUILDLINK_PKGSRCDIR.libmwaw?=	../../converters/libmwaw

.include "../../converters/libwpg/buildlink3.mk"
#.include "../../devel/zlib/buildlink3.mk"
.endif	# LIBMWAW_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmwaw
