# $NetBSD: buildlink3.mk,v 1.2 2023/08/14 05:24:35 wiz Exp $

BUILDLINK_TREE+=	libiptcdata

.if !defined(LIBIPTCDATA_BUILDLINK3_MK)
LIBIPTCDATA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libiptcdata+=	libiptcdata>=1.0.4
BUILDLINK_ABI_DEPENDS.libiptcdata?=	libiptcdata>=1.0.4nb3
BUILDLINK_PKGSRCDIR.libiptcdata?=	../../graphics/libiptcdata

.endif	# LIBIPTCDATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libiptcdata
