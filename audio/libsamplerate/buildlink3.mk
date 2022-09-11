# $NetBSD: buildlink3.mk,v 1.14 2022/09/11 12:51:04 wiz Exp $

BUILDLINK_TREE+=	libsamplerate

.if !defined(LIBSAMPLERATE_BUILDLINK3_MK)
LIBSAMPLERATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsamplerate+=	libsamplerate>=0.0.13nb1
BUILDLINK_ABI_DEPENDS.libsamplerate+=	libsamplerate>=0.2.2nb2
BUILDLINK_PKGSRCDIR.libsamplerate?=	../../audio/libsamplerate

.include "../../audio/libsndfile/buildlink3.mk"
.endif # LIBSAMPLERATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsamplerate
