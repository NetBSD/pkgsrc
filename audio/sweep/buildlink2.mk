# $NetBSD: buildlink2.mk,v 1.3 2003/05/02 12:06:33 wiz Exp $
#
# This Makefile fragment is included by packages that use sweep.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(SWEEP_BUILDLINK2_MK)
SWEEP_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			sweep
BUILDLINK_DEPENDS.sweep?=		sweep>=0.8.2nb1
BUILDLINK_PKGSRCDIR.sweep?=		../../audio/sweep

EVAL_PREFIX+=	BUILDLINK_PREFIX.sweep=sweep
BUILDLINK_PREFIX.sweep_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.sweep+=	include/sweep/*
BUILDLINK_FILES.sweep+=	lib/sweep/*

.include "../../audio/libvorbis/buildlink2.mk"
.include "../../audio/libsamplerate/buildlink2.mk"
.include "../../audio/libsndfile/buildlink2.mk"
.include "../../audio/mad/buildlink2.mk"
.include "../../audio/Speex/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../databases/tdb/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

BUILDLINK_TARGETS+=	sweep-buildlink

sweep-buildlink: _BUILDLINK_USE

.endif	# SWEEP_BUILDLINK2_MK
