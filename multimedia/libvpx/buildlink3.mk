# $NetBSD: buildlink3.mk,v 1.5 2016/08/16 23:53:25 ryoon Exp $

BUILDLINK_TREE+=	libvpx

.if !defined(LIBVPX_BUILDLINK3_MK)
LIBVPX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvpx+=	libvpx>=1.6.0
BUILDLINK_ABI_DEPENDS.libvpx+=	libvpx>=1.6.0
BUILDLINK_PKGSRCDIR.libvpx?=	../../multimedia/libvpx

.include "../../mk/pthread.buildlink3.mk"
.endif # LIBVPX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvpx
