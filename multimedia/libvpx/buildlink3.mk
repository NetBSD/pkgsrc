# $NetBSD: buildlink3.mk,v 1.8 2022/06/28 11:34:56 wiz Exp $

BUILDLINK_TREE+=	libvpx

.if !defined(LIBVPX_BUILDLINK3_MK)
LIBVPX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvpx+=	libvpx>=1.6.0
BUILDLINK_ABI_DEPENDS.libvpx+=	libvpx>=1.11.0nb1
BUILDLINK_PKGSRCDIR.libvpx?=	../../multimedia/libvpx

GCC_REQD+=	4.8

.include "../../mk/pthread.buildlink3.mk"
.endif # LIBVPX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvpx
