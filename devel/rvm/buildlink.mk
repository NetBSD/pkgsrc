# $NetBSD: buildlink.mk,v 1.8 2001/07/27 13:33:26 jlam Exp $
#
# This Makefile fragment is included by packages that use rvm.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.rvm to the dependency pattern
#     for the version of rvm desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(RVM_BUILDLINK_MK)
RVM_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.rvm?=	rvm>=1.3
DEPENDS+=		${BUILDLINK_DEPENDS.rvm}:../../devel/rvm

EVAL_PREFIX+=		BUILDLINK_PREFIX.rvm=rvm
BUILDLINK_PREFIX.rvm_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.rvm=	include/rvm/*
BUILDLINK_FILES.rvm+=	lib/librds.*
BUILDLINK_FILES.rvm+=	lib/librdslwp.*
BUILDLINK_FILES.rvm+=	lib/librvm.*
BUILDLINK_FILES.rvm+=	lib/librvmlwp.*
BUILDLINK_FILES.rvm+=	lib/libseg.*

.include "../../devel/lwp/buildlink.mk"

BUILDLINK_TARGETS.rvm=	rvm-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.rvm}

pre-configure: ${BUILDLINK_TARGETS.rvm}
rvm-buildlink: _BUILDLINK_USE

.endif	# RVM_BUILDLINK_MK
