# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/12/14 18:23:16 jmmv Exp $
#
# This Makefile fragment is included by packages that use libsamplerate.
#
# This file was created automatically using createbuildlink 2.2.
#

.if !defined(LIBSAMPLERATE_BUILDLINK2_MK)
LIBSAMPLERATE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libsamplerate
BUILDLINK_DEPENDS.libsamplerate?=	libsamplerate>=0.0.13
BUILDLINK_PKGSRCDIR.libsamplerate?=	../../audio/libsamplerate

EVAL_PREFIX+=	BUILDLINK_PREFIX.libsamplerate=libsamplerate
BUILDLINK_PREFIX.libsamplerate_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libsamplerate+=	include/samplerate.h
BUILDLINK_FILES.libsamplerate+=	lib/libsamplerate.*
BUILDLINK_FILES.libsamplerate+=	lib/pkgconfig/samplerate.pc

.include "../../audio/libsndfile/buildlink2.mk"
.include "../../math/fftw/buildlink2.mk"

BUILDLINK_TARGETS+=	libsamplerate-buildlink

libsamplerate-buildlink: _BUILDLINK_USE

.endif	# LIBSAMPLERATE_BUILDLINK2_MK
