# $NetBSD: buildlink2.mk,v 1.2 2003/11/16 14:01:20 agc Exp $
#
# This Makefile fragment is included by packages that use opensp.
#

.if !defined(OPENSP_BUILDLINK2_MK)
OPENSP_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			opensp
BUILDLINK_DEPENDS.opensp?=		opensp>=1.5nb1
BUILDLINK_PKGSRCDIR.opensp?=		../../textproc/opensp

EVAL_PREFIX+=	BUILDLINK_PREFIX.opensp=opensp
BUILDLINK_PREFIX.opensp_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.opensp+=	include/OpenSP/*.cxx
BUILDLINK_FILES.opensp+=	include/OpenSP/*.h
BUILDLINK_FILES.opensp+=	lib/libosp.*

PTHREAD_OPTS+=          native

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
.  include "../../devel/unproven-pthreads/buildlink2.mk"
.endif

BUILDLINK_TARGETS+=	opensp-buildlink

opensp-buildlink: _BUILDLINK_USE

.endif	# OPENSP_BUILDLINK2_MK
