# $NetBSD: buildlink3.mk,v 1.1 2013/08/24 16:09:56 jaapb Exp $

BUILDLINK_TREE+=	libmwaw

.if !defined(LIBMWAW_BUILDLINK3_MK)
LIBMWAW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmwaw+=	libmwaw>=0.1.10
BUILDLINK_PKGSRCDIR.libmwaw?=	../../converters/libmwaw

.include "../../converters/libwpd/buildlink3.mk"
#.include "../../devel/zlib/buildlink3.mk"
.endif	# LIBMWAW_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmwaw
