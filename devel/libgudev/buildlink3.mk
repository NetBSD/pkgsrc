# $NetBSD: buildlink3.mk,v 1.3 2025/10/23 20:36:30 wiz Exp $

BUILDLINK_TREE+=	libgudev

.if !defined(LIBGUDEV_BUILDLINK3_MK)
LIBGUDEV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgudev+=	libgudev>=238
BUILDLINK_ABI_DEPENDS.libgudev?=		libgudev>=238nb2
BUILDLINK_PKGSRCDIR.libgudev?=		../../devel/libgudev

BUILDLINK_INCDIRS.libgudev?=	include/gudev-1.0/gudev

.include "../../sysutils/libudev/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.endif	# LIBGUDEV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgudev
