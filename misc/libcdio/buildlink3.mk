# $NetBSD: buildlink3.mk,v 1.13 2012/09/23 05:36:23 obache Exp $

BUILDLINK_TREE+=	libcdio

.if !defined(LIBCDIO_BUILDLINK3_MK)
LIBCDIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcdio+=	libcdio>=0.65
BUILDLINK_ABI_DEPENDS.libcdio+=	libcdio>=0.83
BUILDLINK_PKGSRCDIR.libcdio?=	../../misc/libcdio
.endif # LIBCDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcdio
