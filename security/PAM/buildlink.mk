# $NetBSD: buildlink.mk,v 1.11 2002/01/29 17:10:10 jlam Exp $
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

BUILDLINK_DEPENDS.pam?=	PAM>=0.75

.if exists(/usr/include/security/pam_appl.h)
_NEED_PAM=		NO
.else
_NEED_PAM=		YES
.endif

.if ${_NEED_PAM} == "YES"

DEPENDS+=		${BUILDLINK_DEPENDS.pam}:../../security/PAM
EVAL_PREFIX+=		BUILDLINK_PREFIX.pam=PAM
BUILDLINK_PREFIX.pam_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.pam=	include/security/*
BUILDLINK_FILES.pam+=	lib/libpam.*
BUILDLINK_FILES.pam+=	lib/libpamc.*
BUILDLINK_FILES.pam+=	lib/libpam_misc.*

BUILDLINK_TARGETS.pam=	pam-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.pam}

.else

# The PAM libraries are usually in /lib on Linux systems while the headers
# are in /usr/include.
#
BUILDLINK_PREFIX.pam-inc=	/usr
BUILDLINK_FILES.pam-inc=	include/security/*
BUILDLINK_PREFIX.pam-lib=	/
BUILDLINK_FILES.pam-lib+=	lib/libpam.*
BUILDLINK_FILES.pam-lib+=	lib/libpamc.*
BUILDLINK_FILES.pam-lib+=	lib/libpam_misc.*

BUILDLINK_TARGETS.pam=		pam-inc-buildlink
BUILDLINK_TARGETS.pam+=		pam-lib-buildlink

.endif

pre-configure: ${BUILDLINK_TARGETS.pam}
pam-buildlink: _BUILDLINK_USE
pam-inc-buildlink: _BUILDLINK_USE
pam-lib-buildlink: _BUILDLINK_USE

.endif	# PAM_BUILDLINK_MK
