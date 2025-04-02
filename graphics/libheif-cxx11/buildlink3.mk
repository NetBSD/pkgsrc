# $NetBSD: buildlink3.mk,v 1.1 2025/04/02 13:03:14 nia Exp $

BUILDLINK_TREE+=	libheif

.if !defined(LIBHEIF_BUILDLINK3_MK)
LIBHEIF_BUILDLINK3_MK:=

USE_CXX_FEATURES+=		c++11

BUILDLINK_API_DEPENDS.libheif+=	libheif>=1.8.0
BUILDLINK_ABI_DEPENDS.libheif+=	libheif>=1.18.0<=1.19.0
BUILDLINK_PKGSRCDIR.libheif?=	../../graphics/libheif-cxx11
.endif	# LIBHEIF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libheif
