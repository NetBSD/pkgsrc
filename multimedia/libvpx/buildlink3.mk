# $NetBSD: buildlink3.mk,v 1.6 2017/01/16 23:45:10 wiz Exp $

BUILDLINK_TREE+=	libvpx

.if !defined(LIBVPX_BUILDLINK3_MK)
LIBVPX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvpx+=	libvpx>=1.6.0
BUILDLINK_ABI_DEPENDS.libvpx+=	libvpx>=1.6.1
BUILDLINK_PKGSRCDIR.libvpx?=	../../multimedia/libvpx

.include "../../mk/pthread.buildlink3.mk"
.endif # LIBVPX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvpx
