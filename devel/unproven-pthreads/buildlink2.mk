# $NetBSD: buildlink2.mk,v 1.6 2002/10/09 10:32:54 jlam Exp $

.if !defined(UNPROVEN_PTHREADS_BUILDLINK2_MK)
UNPROVEN_PTHREADS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			unproven-pthreads
BUILDLINK_DEPENDS.unproven-pthreads?=	unproven-pthreads>=0.17
BUILDLINK_PKGSRCDIR.unproven-pthreads?=	../../devel/unproven-pthreads

EVAL_PREFIX+=	BUILDLINK_PREFIX.unproven-pthreads=unproven-pthreads
BUILDLINK_PREFIX.unproven-pthreads_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.unproven-pthreads=	pthreads/include/*.h
BUILDLINK_FILES.unproven-pthreads+=	pthreads/include/*/*.h
BUILDLINK_FILES.unproven-pthreads+=	pthreads/lib/libpthread.*

BUILDLINK_CPPFLAGS.unproven-pthreads= \
	-I${BUILDLINK_PREFIX.unproven-pthreads}/pthreads/include
BUILDLINK_LDFLAGS.unproven-pthreads= \
	-L${BUILDLINK_PREFIX.unproven-pthreads}/pthreads/lib

PGCC=	${BUILDLINK_PREFIX.unproven-pthreads}/pthreads/bin/pgcc
PGXX=	${BUILDLINK_PREFIX.unproven-pthreads}/pthreads/bin/pg++

BUILDLINK_ENV+=	CC="${PGCC}"
BUILDLINK_ENV+=	CXX="${PGXX}"

BUILDLINK_TARGETS+=	unproven-pthreads-buildlink

unproven-pthreads-buildlink: _BUILDLINK_USE

.endif	# UNPROVEN_PTHREADS_BUILDLINK2_MK
