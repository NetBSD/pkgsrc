# $NetBSD: buildlink2.mk,v 1.2 2004/02/19 17:54:05 wiz Exp $

.if !defined(LIBSNDFILE_BUILDLINK2_MK)
LIBSNDFILE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libsndfile
BUILDLINK_DEPENDS.libsndfile?=		libsndfile>=1.0.0
BUILDLINK_PKGSRCDIR.libsndfile?=	../../audio/libsndfile

EVAL_PREFIX+=	BUILDLINK_PREFIX.libsndfile=libsndfile
BUILDLINK_PREFIX.libsndfile_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libsndfile+=	include/sndfile.h
BUILDLINK_FILES.libsndfile+=	lib/libsndfile.*

BUILDLINK_TARGETS+=	libsndfile-buildlink

libsndfile-buildlink: _BUILDLINK_USE

.endif	# LIBSNDFILE_BUILDLINK2_MK
