# $NetBSD: buildlink3.mk,v 1.12 2009/10/31 14:46:51 wiz Exp $

BUILDLINK_TREE+=	libcdio

.if !defined(LIBCDIO_BUILDLINK3_MK)
LIBCDIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcdio+=	libcdio>=0.65
BUILDLINK_ABI_DEPENDS.libcdio+=	libcdio>=0.82
BUILDLINK_PKGSRCDIR.libcdio?=	../../misc/libcdio
.endif # LIBCDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcdio
