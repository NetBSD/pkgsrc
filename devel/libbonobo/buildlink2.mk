# $NetBSD: buildlink2.mk,v 1.11 2004/04/01 18:18:00 jmmv Exp $
#
# This Makefile fragment is included by packages that use libbonobo.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(LIBBONOBO_BUILDLINK2_MK)
LIBBONOBO_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libbonobo
BUILDLINK_DEPENDS.libbonobo?=	libbonobo>=2.6.0
BUILDLINK_PKGSRCDIR.libbonobo?=	../../devel/libbonobo

EVAL_PREFIX+=	BUILDLINK_PREFIX.libbonobo=libbonobo
BUILDLINK_PREFIX.libbonobo_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libbonobo+=	include/bonobo-activation-2.0/bonobo-activation/*
BUILDLINK_FILES.libbonobo+=	include/libbonobo-2.0/bonobo/*
BUILDLINK_FILES.libbonobo+=	include/libbonobo-2.0/libbonobo.h
BUILDLINK_FILES.libbonobo+=	lib/libbonobo-2.*
BUILDLINK_FILES.libbonobo+=	lib/libbonobo-activation.*
BUILDLINK_FILES.libbonobo+=	share/idl/bonobo-2.0/*
BUILDLINK_FILES.libbonobo+=	share/idl/bonobo-activation-2.0/*

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../net/ORBit2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"

BUILDLINK_TARGETS+=	libbonobo-buildlink

libbonobo-buildlink: _BUILDLINK_USE

.endif	# LIBBONOBO_BUILDLINK2_MK
