# $NetBSD: buildlink2.mk,v 1.4 2003/07/13 13:52:46 wiz Exp $

.if !defined(RPM_BUILDLINK2_MK)
RPM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		rpm
BUILDLINK_DEPENDS.rpm?=		rpm>=2.5.4nb1
BUILDLINK_PKGSRCDIR.rpm?=	../../misc/rpm

# This adds a build-dependency as rpm only has a static library.
BUILDLINK_DEPMETHOD.rpm?=	build

EVAL_PREFIX+=	BUILDLINK_PREFIX.rpm=rpm
BUILDLINK_PREFIX.rpm_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.rpm=	include/rpm/*
BUILDLINK_FILES.rpm+=	lib/librpm.a

BUILDLINK_CPPFLAGS.rpm=	-I${BUILDLINK_PREFIX.rpm}/include/rpm

.include "../../devel/gettext-lib/buildlink2.mk"

BUILDLINK_TARGETS+=	rpm-buildlink

rpm-buildlink: _BUILDLINK_USE

.endif	# RPM_BUILDLINK2_MK
