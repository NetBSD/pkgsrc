# $NetBSD: buildlink2.mk,v 1.1 2003/06/04 17:15:35 jmmv Exp $
#
# This Makefile fragment is included by packages that use libevent.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(LIBEVENT_BUILDLINK2_MK)
LIBEVENT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libevent
BUILDLINK_DEPENDS.libevent?=		libevent>=0.6
BUILDLINK_PKGSRCDIR.libevent?=		../../devel/libevent

EVAL_PREFIX+=	BUILDLINK_PREFIX.libevent=libevent
BUILDLINK_PREFIX.libevent_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libevent+=	include/event.h
BUILDLINK_FILES.libevent+=	lib/libevent.*

BUILDLINK_TARGETS+=	libevent-buildlink

libevent-buildlink: _BUILDLINK_USE

.endif	# LIBEVENT_BUILDLINK2_MK
