# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/06/05 20:50:29 wiz Exp $
#
# This Makefile fragment is included by packages that use fftw2.
#
# This file was created automatically using createbuildlink 2.2.
#

.if !defined(FFTW2_BUILDLINK2_MK)
FFTW2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			fftw2
BUILDLINK_DEPENDS.fftw2?=		fftw2>=2.1.3
BUILDLINK_PKGSRCDIR.fftw2?=		../../math/fftw2

EVAL_PREFIX+=	BUILDLINK_PREFIX.fftw2=fftw2
BUILDLINK_PREFIX.fftw2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.fftw2+=	include/fftw.h
BUILDLINK_FILES.fftw2+=	include/rfftw.h
BUILDLINK_FILES.fftw2+=	lib/libfftw.*
BUILDLINK_FILES.fftw2+=	lib/librfftw.*

BUILDLINK_TARGETS+=	fftw2-buildlink

fftw2-buildlink: _BUILDLINK_USE

.endif	# FFTW2_BUILDLINK2_MK
