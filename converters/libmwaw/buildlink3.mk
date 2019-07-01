# $NetBSD: buildlink3.mk,v 1.14 2019/07/01 04:07:45 ryoon Exp $

BUILDLINK_TREE+=	libmwaw

.if !defined(LIBMWAW_BUILDLINK3_MK)
LIBMWAW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmwaw+=	libmwaw>=0.2.0
BUILDLINK_ABI_DEPENDS.libmwaw?=	libmwaw>=0.3.7nb9
BUILDLINK_PKGSRCDIR.libmwaw?=	../../converters/libmwaw

.include "../../converters/libwpg/buildlink3.mk"
#.include "../../devel/zlib/buildlink3.mk"
.endif	# LIBMWAW_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmwaw
