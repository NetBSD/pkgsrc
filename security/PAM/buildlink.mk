# $NetBSD: buildlink.mk,v 1.6 2001/06/11 01:59:38 jlam Exp $
#
# This Makefile fragment is included by packages that use libpam.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define PAM_REQD to the version of pam desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(PAM_BUILDLINK_MK)
PAM_BUILDLINK_MK=	# defined

PAM_REQD?=		0.72
DEPENDS+=		PAM>=${PAM_REQD}:../../security/PAM

BUILDLINK_PREFIX.pam=	${LOCALBASE}
BUILDLINK_FILES.pam=	include/security/*
BUILDLINK_FILES.pam+=	lib/libpam.*
BUILDLINK_FILES.pam+=	lib/libpamc.*
BUILDLINK_FILES.pam+=	lib/libpam_misc.*

BUILDLINK_TARGETS.pam=	pam-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.pam}

pre-configure: ${BUILDLINK_TARGETS.pam}
pam-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# PAM_BUILDLINK_MK
