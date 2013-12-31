# $NetBSD: buildlink3.mk,v 1.2 2013/12/31 23:21:08 ryoon Exp $

BUILDLINK_TREE+=	libmediainfo

.if !defined(LIBMEDIAINFO_BUILDLINK3_MK)
LIBMEDIAINFO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmediainfo+=	libmediainfo>=0.7.65
BUILDLINK_PKGSRCDIR.libmediainfo?=	../../multimedia/libmediainfo

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libzen/buildlink3.mk"
.endif	# LIBMEDIAINFO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmediainfo
