# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:22:42 jlam Exp $

.if !defined(UNPROVEN_PTHREADS_BUILDLINK2_MK)
UNPROVEN_PTHREADS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			unproven-pthreads
BUILDLINK_DEPENDS.unproven-pthreads?=	unproven-pthreads>=0.17
BUILDLINK_PKGSRCDIR.unproven-pthreads?=	../../devel/unproven-pthreads

EVAL_PREFIX+=	BUILDLINK_PREFIX.unproven-pthreads=unproven-pthreads
BUILDLINK_PREFIX.unproven-pthreads_DEFAULT=	${LOCALBASE}

CC=	${BUILDLINK_PREFIX.unproven-pthreads}/pthreads/bin/pgcc
CXX=	${BUILDLINK_PREFIX.unproven-pthreads}/pthreads/bin/pg++

.endif	# UNPROVEN_PTHREADS_BUILDLINK2_MK
