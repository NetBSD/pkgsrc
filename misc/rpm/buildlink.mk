# $NetBSD: buildlink.mk,v 1.6 2001/07/27 13:33:32 jlam Exp $
#
# This Makefile fragment is included by packages that use rpm.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.rpm to the dependency pattern
#     for the version of rpm desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(RPM_BUILDLINK_MK)
RPM_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

# This adds a build-dependency as rpm only has a static library.
BUILDLINK_DEPENDS.rpm?=	rpm>=2.4.3
BUILD_DEPENDS+=		${BUILDLINK_DEPENDS.rpm}:../../misc/rpm

EVAL_PREFIX+=		BUILDLINK_PREFIX.rpm=rpm
BUILDLINK_PREFIX.rpm_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.rpm=	include/rpm/*
BUILDLINK_FILES.rpm+=	lib/librpm.a

.include "../../devel/gettext-lib/buildlink.mk"

BUILDLINK_TARGETS.rpm=	rpm-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.rpm}

pre-configure: ${BUILDLINK_TARGETS.rpm}
rpm-buildlink: _BUILDLINK_USE

.endif	# RPM_BUILDLINK_MK
