# $NetBSD: buildlink.mk,v 1.1 2001/06/18 10:24:49 jlam Exp $
#
# This Makefile fragment is included by packages that use rpm.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define RPM_REQD to the version of rpm desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(RPM_BUILDLINK_MK)
RPM_BUILDLINK_MK=	# defined

# This adds a build-dependency as rpm only has a static library.
RPM_REQD?=		2.4.3
BUILD_DEPENDS+=		rpm>=${RPM_REQD}:../../misc/rpm

BUILDLINK_PREFIX.rpm=	${LOCALBASE}
BUILDLINK_FILES.rpm=	include/rpm/*
BUILDLINK_FILES.rpm+=	lib/librpm.a

BUILDLINK_TARGETS.rpm=	rpm-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.rpm}

pre-configure: ${BUILDLINK_TARGETS.rpm}
rpm-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# RPM_BUILDLINK_MK
