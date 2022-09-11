# $NetBSD: buildlink3.mk,v 1.19 2022/09/11 12:51:04 wiz Exp $

BUILDLINK_TREE+=	libsndfile

.if !defined(LIBSNDFILE_BUILDLINK3_MK)
LIBSNDFILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsndfile+=	libsndfile>=1.0.0
BUILDLINK_ABI_DEPENDS.libsndfile+=	libsndfile>=1.1.0nb2
BUILDLINK_PKGSRCDIR.libsndfile?=	../../audio/libsndfile

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.endif # LIBSNDFILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsndfile
