# $NetBSD: buildlink3.mk,v 1.13 2022/03/28 10:43:35 tnn Exp $

BUILDLINK_TREE+=	libsamplerate

.if !defined(LIBSAMPLERATE_BUILDLINK3_MK)
LIBSAMPLERATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsamplerate+=	libsamplerate>=0.0.13nb1
BUILDLINK_ABI_DEPENDS.libsamplerate+=	libsamplerate>=0.2.2nb1
BUILDLINK_PKGSRCDIR.libsamplerate?=	../../audio/libsamplerate

.include "../../audio/libsndfile/buildlink3.mk"
.endif # LIBSAMPLERATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsamplerate
