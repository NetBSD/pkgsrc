# $NetBSD: buildlink3.mk,v 1.3 2025/12/26 11:10:46 adam Exp $

BUILDLINK_TREE+=	libcdio-paranoia

.if !defined(LIBCDIO_PARANOIA_BUILDLINK3_MK)
LIBCDIO_PARANOIA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcdio-paranoia+=	libcdio-paranoia>=0.93
BUILDLINK_ABI_DEPENDS.libcdio-paranoia+=	libcdio-paranoia>=2.0.1nb4
BUILDLINK_PKGSRCDIR.libcdio-paranoia?=		../../misc/libcdio-paranoia

.include "../../misc/libcdio/buildlink3.mk"
.endif	# LIBCDIO_PARANOIA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcdio-paranoia
