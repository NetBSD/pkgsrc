# $NetBSD: buildlink2.mk,v 1.4 2003/12/08 14:41:38 wiz Exp $
#
# This Makefile fragment is included by packages that use speex.
#

.if !defined(SPEEX_BUILDLINK2_MK)
SPEEX_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			speex
BUILDLINK_DEPENDS.speex?=		speex>=1.0.2nb1
BUILDLINK_PKGSRCDIR.speex?=		../../audio/speex

EVAL_PREFIX+=	BUILDLINK_PREFIX.speex=speex
BUILDLINK_PREFIX.speex_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.speex+=	include/speex.h
BUILDLINK_FILES.speex+=	include/speex_bits.h
BUILDLINK_FILES.speex+=	include/speex_callbacks.h
BUILDLINK_FILES.speex+=	include/speex_header.h
BUILDLINK_FILES.speex+=	include/speex_stereo.h
BUILDLINK_FILES.speex+=	lib/libspeex.*

.include "../../audio/libogg/buildlink2.mk"

BUILDLINK_TARGETS+=	speex-buildlink

speex-buildlink: _BUILDLINK_USE

.endif	# SPEEX_BUILDLINK2_MK
