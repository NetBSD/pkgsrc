# $NetBSD: buildlink2.mk,v 1.1 2002/08/31 02:02:22 jlam Exp $

.if !defined(LIBSNDFILE_BUILDLINK2_MK)
LIBSNDFILE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libsndfile
BUILDLINK_DEPENDS.libsndfile?=		libsndfile>=1.0.0
BUILDLINK_PKGSRCDIR.libsndfile?=	../../audio/libsndfile

EVAL_PREFIX+=	BUILDLINK_PREFIX.libsndfile=libsndfile
BUILDLINK_PREFIX.libsndfile_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libsndfile+=	include/sndfile.h
BUILDLINK_FILES.libsndfile+=	lib/libsndfile.*

.include "../../devel/pkgconfig/buildlink2.mk"

BUILDLINK_TARGETS+=	libsndfile-buildlink

libsndfile-buildlink: _BUILDLINK_USE

.endif	# LIBSNDFILE_BUILDLINK2_MK
