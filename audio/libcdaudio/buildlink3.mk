# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:23:54 joerg Exp $

BUILDLINK_TREE+=	libcdaudio

.if !defined(LIBCDAUDIO_BUILDLINK3_MK)
LIBCDAUDIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcdaudio+=		libcdaudio>=0.99.4nb1
BUILDLINK_ABI_DEPENDS.libcdaudio+=	libcdaudio>=0.99.12nb1
BUILDLINK_PKGSRCDIR.libcdaudio?=	../../audio/libcdaudio
.endif # LIBCDAUDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcdaudio
