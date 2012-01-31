# $NetBSD: buildlink3.mk,v 1.2 2012/01/31 11:53:51 ryoon Exp $

BUILDLINK_TREE+=	libvpx

.if !defined(LIBVPX_BUILDLINK3_MK)
LIBVPX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvpx+=	libvpx>=0.9.2
BUILDLINK_ABI_DEPENDS.libvpx+=	libvpx>=1.0.0
BUILDLINK_PKGSRCDIR.libvpx?=	../../multimedia/libvpx

.include "../../mk/pthread.buildlink3.mk"
.endif # LIBVPX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvpx
