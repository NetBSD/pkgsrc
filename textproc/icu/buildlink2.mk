# $NetBSD: buildlink2.mk,v 1.5 2004/04/04 16:58:16 recht Exp $

.if !defined(ICU_BUILDLINK2_MK)
ICU_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		icu
BUILDLINK_DEPENDS.icu?=	icu>=2.8
BUILDLINK_PKGSRCDIR.icu?=	../../textproc/icu

EVAL_PREFIX+=	BUILDLINK_PREFIX.icu=icu
BUILDLINK_PREFIX.icu_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.icu+=	include/layout/*.h
BUILDLINK_FILES.icu+=	include/unicode/*.h
BUILDLINK_FILES.icu+=	lib/icu/${PKGVERSION}/Makefile.inc
BUILDLINK_FILES.icu+=	lib/icu/Makefile.inc
BUILDLINK_FILES.icu+=	lib/icu/current
BUILDLINK_FILES.icu+=	lib/libicudata.*
BUILDLINK_FILES.icu+=	lib/libicui18n.*
BUILDLINK_FILES.icu+=	lib/libicuio.*
BUILDLINK_FILES.icu+=	lib/libicule.*
BUILDLINK_FILES.icu+=	lib/libiculx.*
BUILDLINK_FILES.icu+=	lib/libicutoolutil.*
BUILDLINK_FILES.icu+=	lib/libicuuc.*
BUILDLINK_FILES.icu+=	lib/libsicudata.*
BUILDLINK_FILES.icu+=	lib/libsicui18n.*
BUILDLINK_FILES.icu+=	lib/libsicuio.*
BUILDLINK_FILES.icu+=	lib/libsicule.*
BUILDLINK_FILES.icu+=	lib/libsiculx.*
BUILDLINK_FILES.icu+=	lib/libsicutoolutil.*
BUILDLINK_FILES.icu+=	lib/libsicuuc.*
BUILDLINK_TARGETS+=	icu-buildlink

icu-buildlink: _BUILDLINK_USE

.endif	# ICU_BUILDLINK2_MK
