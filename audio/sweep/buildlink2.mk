# $NetBSD: buildlink2.mk,v 1.7 2003/12/08 14:41:38 wiz Exp $
#
# This Makefile fragment is included by packages that use sweep.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(SWEEP_BUILDLINK2_MK)
SWEEP_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			sweep
BUILDLINK_DEPENDS.sweep?=		sweep>=0.8.2nb6
BUILDLINK_PKGSRCDIR.sweep?=		../../audio/sweep

EVAL_PREFIX+=	BUILDLINK_PREFIX.sweep=sweep
BUILDLINK_PREFIX.sweep_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.sweep+=	include/sweep/*
BUILDLINK_FILES.sweep+=	lib/sweep/*

.include "../../audio/libmad/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../audio/libsamplerate/buildlink2.mk"
.include "../../audio/libsndfile/buildlink2.mk"
.include "../../audio/speex/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../databases/tdb/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

BUILDLINK_TARGETS+=	sweep-buildlink

sweep-buildlink: _BUILDLINK_USE

.endif	# SWEEP_BUILDLINK2_MK
