# $NetBSD: buildlink2.mk,v 1.1 2002/09/27 09:04:41 rh Exp $
#
# This Makefile fragment is included by packages that use ffcall.
#
# This file was created automatically using createbuildlink 2.0.
#

.if !defined(FFCALL_BUILDLINK2_MK)
FFCALL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			ffcall
BUILDLINK_DEPENDS.ffcall?=		ffcall>=1.8.4
BUILDLINK_PKGSRCDIR.ffcall?=		../../devel/ffcall

EVAL_PREFIX+=	BUILDLINK_PREFIX.ffcall=ffcall
BUILDLINK_PREFIX.ffcall_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.ffcall+=	include/avcall.h
BUILDLINK_FILES.ffcall+=	include/vacall.h
BUILDLINK_FILES.ffcall+=	include/trampoline.h
BUILDLINK_FILES.ffcall+=	include/vacall_r.h
BUILDLINK_FILES.ffcall+=	include/trampoline_r.h
BUILDLINK_FILES.ffcall+=	include/callback.h
BUILDLINK_FILES.ffcall+=	lib/libavcall.*
BUILDLINK_FILES.ffcall+=	lib/libcallback.*
BUILDLINK_FILES.ffcall+=	lib/libtrampoline.*
BUILDLINK_FILES.ffcall+=	lib/libvacall.*


BUILDLINK_TARGETS+=	ffcall-buildlink

ffcall-buildlink: _BUILDLINK_USE

.endif	# FFCALL_BUILDLINK2_MK
