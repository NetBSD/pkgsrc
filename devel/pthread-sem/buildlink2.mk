# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/01/20 21:29:10 rh Exp $
#
# This Makefile fragment is included by packages that use pthread-sem.
#

.if !defined(PTHREAD_SEM_BUILDLINK2_MK)
PTHREAD_SEM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			pthread-sem
BUILDLINK_DEPENDS.pthread-sem?=		pthread-sem>=1.0
BUILDLINK_PKGSRCDIR.pthread-sem?=	../../devel/pthread-sem

EVAL_PREFIX+=	BUILDLINK_PREFIX.pthread-sem=pthread-sem
BUILDLINK_PREFIX.pthread-sem_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pthread-sem+=	include/semaphore.h
BUILDLINK_FILES.pthread-sem+=	lib/libsemaphore.*
BUILDLINK_FILES.pthread-sem+=	lib/libsemaphore_pic.*

BUILDLINK_TARGETS+=	pthread-sem-buildlink

pthread-sem-buildlink: _BUILDLINK_USE

.endif	# PTHREAD_SEM_BUILDLINK2_MK
