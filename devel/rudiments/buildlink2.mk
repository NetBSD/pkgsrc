# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/04/15 10:32:33 grant Exp $
#
# This Makefile fragment is included by packages that use rudiments.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(RUDIMENTS_BUILDLINK2_MK)
RUDIMENTS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			rudiments
BUILDLINK_DEPENDS.rudiments?=		rudiments>=0.25.1
BUILDLINK_PKGSRCDIR.rudiments?=		../../devel/rudiments

EVAL_PREFIX+=	BUILDLINK_PREFIX.rudiments=rudiments
BUILDLINK_PREFIX.rudiments_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.rudiments+=	include/rudiments/*
BUILDLINK_FILES.rudiments+=	include/rudiments/*/*
BUILDLINK_FILES.rudiments+=	lib/lib${PKGNAME}.*
BUILDLINK_FILES.rudiments+=	lib/librudiments.*
BUILDLINK_FILES.rudiments+=	lib/librudiments_p-${PKGVERSION}.*
BUILDLINK_FILES.rudiments+=	lib/librudiments_p.*

BUILDLINK_TARGETS+=	rudiments-buildlink

rudiments-buildlink: _BUILDLINK_USE

.endif	# RUDIMENTS_BUILDLINK2_MK
