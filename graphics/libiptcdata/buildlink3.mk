# $NetBSD: buildlink3.mk,v 1.1 2016/07/10 21:57:47 kamil Exp $

BUILDLINK_TREE+=	libiptcdata

.if !defined(LIBIPTCDATA_BUILDLINK3_MK)
LIBIPTCDATA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libiptcdata+=	libiptcdata>=1.0.4
BUILDLINK_PKGSRCDIR.libiptcdata?=	../../graphics/libiptcdata

.endif	# LIBIPTCDATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libiptcdata
