# $NetBSD: buildlink3.mk,v 1.1 2025/08/31 12:03:35 ryoon Exp $

BUILDLINK_TREE+=	libdovi

.if !defined(LIBDOVI_BUILDLINK3_MK)
LIBDOVI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdovi+=	libdovi>=2.3.0
BUILDLINK_PKGSRCDIR.libdovi?=	../../audio/libdovi

#.include "../../fonts/fontconfig/buildlink3.mk"
.endif	# LIBDOVI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdovi
