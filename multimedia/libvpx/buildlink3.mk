# $NetBSD: buildlink3.mk,v 1.4 2015/11/18 14:09:25 ryoon Exp $

BUILDLINK_TREE+=	libvpx

.if !defined(LIBVPX_BUILDLINK3_MK)
LIBVPX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvpx+=	libvpx>=1.5.0
BUILDLINK_ABI_DEPENDS.libvpx+=	libvpx>=1.5.0
BUILDLINK_PKGSRCDIR.libvpx?=	../../multimedia/libvpx

.include "../../mk/pthread.buildlink3.mk"
.endif # LIBVPX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvpx
