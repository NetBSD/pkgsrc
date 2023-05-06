# $NetBSD: buildlink3.mk,v 1.20 2023/05/06 19:08:46 ryoon Exp $

BUILDLINK_TREE+=	libsndfile

.if !defined(LIBSNDFILE_BUILDLINK3_MK)
LIBSNDFILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsndfile+=	libsndfile>=1.0.0
BUILDLINK_ABI_DEPENDS.libsndfile+=	libsndfile>=1.2.0nb2
BUILDLINK_PKGSRCDIR.libsndfile?=	../../audio/libsndfile

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.endif # LIBSNDFILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsndfile
