# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/03/24 08:58:53 wiz Exp $
#
# This Makefile fragment is included by packages that use Speex.
#
# This file was created automatically using createbuildlink 2.2.
#

.if !defined(SPEEX_BUILDLINK2_MK)
SPEEX_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			Speex
BUILDLINK_DEPENDS.Speex?=		Speex>=0.99.3
BUILDLINK_PKGSRCDIR.Speex?=		../../audio/Speex

EVAL_PREFIX+=	BUILDLINK_PREFIX.Speex=Speex
BUILDLINK_PREFIX.Speex_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.Speex+=	include/speex.h
BUILDLINK_FILES.Speex+=	include/speex_bits.h
BUILDLINK_FILES.Speex+=	include/speex_callbacks.h
BUILDLINK_FILES.Speex+=	include/speex_header.h
BUILDLINK_FILES.Speex+=	include/speex_stereo.h
BUILDLINK_FILES.Speex+=	lib/libspeex-0.99.*
BUILDLINK_FILES.Speex+=	lib/libspeex.*

.include "../../audio/libogg/buildlink2.mk"

BUILDLINK_TARGETS+=	Speex-buildlink

Speex-buildlink: _BUILDLINK_USE

.endif	# SPEEX_BUILDLINK2_MK
