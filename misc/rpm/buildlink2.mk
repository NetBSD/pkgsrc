# $NetBSD: buildlink2.mk,v 1.1.2.2 2002/06/06 06:54:43 jlam Exp $
#
# This Makefile fragment is included by packages that use rpm.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.rpm to the dependency pattern
#     for the version of rpm desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(RPM_BUILDLINK2_MK)
RPM_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

# This adds a build-dependency as rpm only has a static library.
BUILDLINK_DEPENDS.rpm?=	rpm>=2.4.3
BUILD_DEPENDS+=		${BUILDLINK_DEPENDS.rpm}:../../misc/rpm

EVAL_PREFIX+=	BUILDLINK_PREFIX.rpm=rpm
BUILDLINK_PREFIX.rpm_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.rpm=	include/rpm/*
BUILDLINK_FILES.rpm+=	lib/librpm.a

.include "../../devel/gettext-lib/buildlink2.mk"

BUILDLINK_TARGETS+=	rpm-buildlink

rpm-buildlink: _BUILDLINK_USE

.endif	# RPM_BUILDLINK2_MK
