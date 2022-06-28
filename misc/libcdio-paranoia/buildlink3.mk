# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:34:48 wiz Exp $

BUILDLINK_TREE+=	libcdio-paranoia

.if !defined(LIBCDIO_PARANOIA_BUILDLINK3_MK)
LIBCDIO_PARANOIA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcdio-paranoia+=	libcdio-paranoia>=0.93
BUILDLINK_ABI_DEPENDS.libcdio-paranoia?=		libcdio-paranoia>=2.0.1nb3
BUILDLINK_PKGSRCDIR.libcdio-paranoia?=		../../misc/libcdio-paranoia

.include "../../misc/libcdio/buildlink3.mk"
.endif	# LIBCDIO_PARANOIA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcdio-paranoia
