# $NetBSD: buildlink2.mk,v 1.3 2003/04/29 22:48:46 jtb Exp $
#
# This Makefile fragment is included by packages that use fftw.
#
# This file was created automatically using createbuildlink 2.2.
#

.if !defined(FFTW_BUILDLINK2_MK)
FFTW_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			fftw
BUILDLINK_DEPENDS.fftw?=		fftw>=3.0
BUILDLINK_PKGSRCDIR.fftw?=		../../math/fftw

EVAL_PREFIX+=	BUILDLINK_PREFIX.fftw=fftw
BUILDLINK_PREFIX.fftw_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.fftw+=	include/fftw3.f
BUILDLINK_FILES.fftw+=	include/fftw3.h
BUILDLINK_FILES.fftw+=	lib/libfftw3.*
BUILDLINK_FILES.fftw+=	lib/librfftw.*

BUILDLINK_TARGETS+=	fftw-buildlink

fftw-buildlink: _BUILDLINK_USE

.endif	# FFTW_BUILDLINK2_MK
