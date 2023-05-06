# $NetBSD: buildlink3.mk,v 1.2 2023/05/06 19:08:46 ryoon Exp $

BUILDLINK_TREE+=	libopusenc

.if !defined(LIBOPUSENC_BUILDLINK3_MK)
LIBOPUSENC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libopusenc+=	libopusenc>=0.2.1
BUILDLINK_ABI_DEPENDS.libopusenc?=	libopusenc>=0.2.1nb1
BUILDLINK_PKGSRCDIR.libopusenc?=	../../audio/libopusenc

.include "../../audio/libopus/buildlink3.mk"
.endif	# LIBOPUSENC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libopusenc
