# $NetBSD: buildlink2.mk,v 1.2 2002/12/14 18:14:02 jmmv Exp $
#
# This Makefile fragment is included by packages that use fftw.
#
# This file was created automatically using createbuildlink 2.2.
#

.if !defined(FFTW_BUILDLINK2_MK)
FFTW_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			fftw
BUILDLINK_DEPENDS.fftw?=		fftw>=2.1.3
BUILDLINK_PKGSRCDIR.fftw?=		../../math/fftw

EVAL_PREFIX+=	BUILDLINK_PREFIX.fftw=fftw
BUILDLINK_PREFIX.fftw_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.fftw+=	include/fftw.h
BUILDLINK_FILES.fftw+=	include/rfftw.h
BUILDLINK_FILES.fftw+=	lib/libfftw.*
BUILDLINK_FILES.fftw+=	lib/librfftw.*

BUILDLINK_TARGETS+=	fftw-buildlink

fftw-buildlink: _BUILDLINK_USE

.endif	# FFTW_BUILDLINK2_MK
