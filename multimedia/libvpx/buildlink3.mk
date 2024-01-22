# $NetBSD: buildlink3.mk,v 1.10 2024/01/22 13:09:26 ryoon Exp $

BUILDLINK_TREE+=	libvpx

.if !defined(LIBVPX_BUILDLINK3_MK)
LIBVPX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvpx+=	libvpx>=1.14.0
BUILDLINK_ABI_DEPENDS.libvpx+=	libvpx>=1.14.0
BUILDLINK_PKGSRCDIR.libvpx?=	../../multimedia/libvpx

USE_CXX_FEATURES+=	c++11

.include "../../mk/pthread.buildlink3.mk"
.endif # LIBVPX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvpx
