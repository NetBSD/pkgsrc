# $NetBSD: buildlink2.mk,v 1.4 2002/10/09 09:49:32 jlam Exp $

.if !defined(UNPROVEN_PTHREADS_BUILDLINK2_MK)
UNPROVEN_PTHREADS_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_PACKAGES+=			unproven-pthreads
BUILDLINK_DEPENDS.unproven-pthreads?=	unproven-pthreads>=0.17
BUILDLINK_PKGSRCDIR.unproven-pthreads?=	../../devel/unproven-pthreads

EVAL_PREFIX+=	BUILDLINK_PREFIX.unproven-pthreads=unproven-pthreads
BUILDLINK_PREFIX.unproven-pthreads_DEFAULT=	${LOCALBASE}

BUILDLINK_CPPFLAGS.unproven-pthreads= \
	-I${BUILDLINK_PREFIX.unproven-pthreads}/pthreads/include
BUILDLINK_LDFLAGS.unproven-pthreads= \
	-L${BUILDLINK_PREFIX.unproven-pthreads}/pthreads/lib

CC=	${BUILDLINK_PREFIX.unproven-pthreads}/pthreads/bin/pgcc
CXX=	${BUILDLINK_PREFIX.unproven-pthreads}/pthreads/bin/pg++

.endif	# UNPROVEN_PTHREADS_BUILDLINK2_MK
