# $NetBSD: buildlink.mk,v 1.10 2001/07/27 13:33:34 jlam Exp $
#
# This Makefile fragment is included by packages that use libpam.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.pam to the dependency pattern
#     for the version of pam desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(PAM_BUILDLINK_MK)
PAM_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.pam?=	PAM>=0.72
DEPENDS+=		${BUILDLINK_DEPENDS.pam}:../../security/PAM

EVAL_PREFIX+=		BUILDLINK_PREFIX.pam=PAM
BUILDLINK_PREFIX.pam_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pam=	include/security/*
BUILDLINK_FILES.pam+=	lib/libpam.*
BUILDLINK_FILES.pam+=	lib/libpamc.*
BUILDLINK_FILES.pam+=	lib/libpam_misc.*

BUILDLINK_TARGETS.pam=	pam-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.pam}

pre-configure: ${BUILDLINK_TARGETS.pam}
pam-buildlink: _BUILDLINK_USE

.endif	# PAM_BUILDLINK_MK
