# $NetBSD: buildlink3.mk,v 1.13 2009/03/20 19:23:57 joerg Exp $

BUILDLINK_TREE+=	libsndfile

.if !defined(LIBSNDFILE_BUILDLINK3_MK)
LIBSNDFILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsndfile+=	libsndfile>=1.0.0
BUILDLINK_ABI_DEPENDS.libsndfile+=	libsndfile>=1.0.18
BUILDLINK_PKGSRCDIR.libsndfile?=	../../audio/libsndfile

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.endif # LIBSNDFILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsndfile
