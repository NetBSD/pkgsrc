# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/05/11 02:09:22 jlam Exp $
#
# This Makefile fragment is included by packages that use libpam.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.pam to the dependency pattern
#     for the version of pam desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(PAM_BUILDLINK2_MK)
PAM_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.pam?=	PAM>=0.75

.if exists(/usr/include/security/pam_appl.h)
_NEED_PAM=		NO
.else
_NEED_PAM=		YES
.endif

.if ${_NEED_PAM} == "YES"

DEPENDS+=	${BUILDLINK_DEPENDS.pam}:../../security/PAM
BUILDLINK_PREFIX.pam=	${LOCALBASE}

BUILDLINK_FILES.pam=	include/security/*
BUILDLINK_FILES.pam+=	lib/libpam.*
BUILDLINK_FILES.pam+=	lib/libpamc.*
BUILDLINK_FILES.pam+=	lib/libpam_misc.*

BUILDLINK_TARGETS+=	pam-buildlink

pam-buildlink: _BUILDLINK_USE

.else

# The PAM libraries are usually in /lib on Linux systems while the headers
# are in /usr/include.
#
BUILDLINK_PREFIX.pam=		/usr
BUILDLINK_PREFIX.pam-inc=	/usr
BUILDLINK_FILES.pam-inc=	include/security/*
BUILDLINK_PREFIX.pam-lib=	/
BUILDLINK_FILES.pam-lib+=	lib/libpam.*
BUILDLINK_FILES.pam-lib+=	lib/libpamc.*
BUILDLINK_FILES.pam-lib+=	lib/libpam_misc.*

BUILDLINK_TARGETS+=	pam-inc-buildlink
BUILDLINK_TARGETS+=	pam-lib-buildlink

pam-inc-buildlink: _BUILDLINK_USE
pam-lib-buildlink: _BUILDLINK_USE

.endif	# _NEED_PAM
.endif	# PAM_BUILDLINK2_MK
