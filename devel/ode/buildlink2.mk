# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/12/03 19:00:56 xtraeme Exp $
#
# This Makefile fragment is included by packages that use ode.
#
# This file was created automatically using createbuildlink 2.7.
#

.if !defined(ODE_BUILDLINK2_MK)
ODE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			ode
BUILDLINK_DEPENDS.ode?=		ode>=0.039
BUILDLINK_PKGSRCDIR.ode?=		../../devel/ode

EVAL_PREFIX+=	BUILDLINK_PREFIX.ode=ode
BUILDLINK_PREFIX.ode_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.ode+=	include/ode/*.h
BUILDLINK_FILES.ode+=	lib/libode.*

BUILDLINK_TARGETS+=	ode-buildlink

ode-buildlink: _BUILDLINK_USE

.endif	# ODE_BUILDLINK2_MK
