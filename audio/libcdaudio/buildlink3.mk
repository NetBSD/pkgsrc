# $NetBSD: buildlink3.mk,v 1.10 2018/01/07 13:03:54 rillig Exp $

BUILDLINK_TREE+=	libcdaudio

.if !defined(LIBCDAUDIO_BUILDLINK3_MK)
LIBCDAUDIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcdaudio+=	libcdaudio>=0.99.4nb1
BUILDLINK_ABI_DEPENDS.libcdaudio+=	libcdaudio>=0.99.12nb1
BUILDLINK_PKGSRCDIR.libcdaudio?=	../../audio/libcdaudio
.endif # LIBCDAUDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcdaudio
