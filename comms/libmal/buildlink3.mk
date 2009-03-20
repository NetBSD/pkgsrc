# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:24:02 joerg Exp $

BUILDLINK_TREE+=	libmal

.if !defined(LIBMAL_BUILDLINK3_MK)
LIBMAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmal+=	libmal>=0.40
BUILDLINK_ABI_DEPENDS.libmal+=	libmal>=0.40nb2
BUILDLINK_PKGSRCDIR.libmal?=	../../comms/libmal

.include "../../comms/pilot-link-libs/buildlink3.mk"
.endif # LIBMAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmal
