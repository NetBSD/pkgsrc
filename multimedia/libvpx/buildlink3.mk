# $NetBSD: buildlink3.mk,v 1.9 2023/07/18 18:34:31 nia Exp $

BUILDLINK_TREE+=	libvpx

.if !defined(LIBVPX_BUILDLINK3_MK)
LIBVPX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvpx+=	libvpx>=1.6.0
BUILDLINK_ABI_DEPENDS.libvpx+=	libvpx>=1.11.0nb1
BUILDLINK_PKGSRCDIR.libvpx?=	../../multimedia/libvpx

USE_CXX_FEATURES+=	c++11

.include "../../mk/pthread.buildlink3.mk"
.endif # LIBVPX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvpx
