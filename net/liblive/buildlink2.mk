# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/04/04 22:37:34 rh Exp $
#
# This Makefile fragment is included by packages that use liblive.
#
# This file was created automatically using createbuildlink 2.5.
#

.if !defined(LIBLIVE_BUILDLINK2_MK)
LIBLIVE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			liblive
BUILDLINK_DEPENDS.liblive?=		liblive>=2003.04.04
BUILDLINK_PKGSRCDIR.liblive?=		../../net/liblive

EVAL_PREFIX+=	BUILDLINK_PREFIX.liblive=liblive
BUILDLINK_PREFIX.liblive_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.liblive+=	include/liblive/BasicUsageEnvironment/*.hh
BUILDLINK_FILES.liblive+=	include/liblive/UsageEnvironment/*.hh
BUILDLINK_FILES.liblive+=	include/liblive/groupsock/*.h
BUILDLINK_FILES.liblive+=	include/liblive/groupsock/*.hh
BUILDLINK_FILES.liblive+=	include/liblive/liveMedia/*.hh
BUILDLINK_FILES.liblive+=	lib/libBasicUsageEnvironment.*
BUILDLINK_FILES.liblive+=	lib/libUsageEnvironment.*
BUILDLINK_FILES.liblive+=	lib/libgroupsock.*
BUILDLINK_FILES.liblive+=	lib/libliveMedia.*

BUILDLINK_TARGETS+=	liblive-buildlink

liblive-buildlink: _BUILDLINK_USE

.endif	# LIBLIVE_BUILDLINK2_MK
