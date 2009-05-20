# $NetBSD: buildlink3.mk,v 1.9 2009/05/20 00:58:08 wiz Exp $

BUILDLINK_TREE+=	libmal

.if !defined(LIBMAL_BUILDLINK3_MK)
LIBMAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmal+=	libmal>=0.40
BUILDLINK_ABI_DEPENDS.libmal+=	libmal>=0.44nb1
BUILDLINK_PKGSRCDIR.libmal?=	../../comms/libmal

.include "../../comms/pilot-link-libs/buildlink3.mk"
.endif # LIBMAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmal
