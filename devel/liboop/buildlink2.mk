# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/09/27 08:14:50 grant Exp $
#
# This Makefile fragment is included by packages that use liboop.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(LIBOOP_BUILDLINK2_MK)
LIBOOP_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			liboop
BUILDLINK_DEPENDS.liboop?=		liboop>=0.9
BUILDLINK_PKGSRCDIR.liboop?=		../../devel/liboop

EVAL_PREFIX+=	BUILDLINK_PREFIX.liboop=liboop
BUILDLINK_PREFIX.liboop_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.liboop+=	include/oop-adns.h
BUILDLINK_FILES.liboop+=	include/oop-glib.h
BUILDLINK_FILES.liboop+=	include/oop-read.h
BUILDLINK_FILES.liboop+=	include/oop-rl.h
BUILDLINK_FILES.liboop+=	include/oop-tcl.h
BUILDLINK_FILES.liboop+=	include/oop-www.h
BUILDLINK_FILES.liboop+=	include/oop.h
BUILDLINK_FILES.liboop+=	lib/liboop-adns.*
BUILDLINK_FILES.liboop+=	lib/liboop-glib.*
BUILDLINK_FILES.liboop+=	lib/liboop-rl.*
BUILDLINK_FILES.liboop+=	lib/liboop-tcl.*
BUILDLINK_FILES.liboop+=	lib/liboop-www.*
BUILDLINK_FILES.liboop+=	lib/liboop.*

.include "../../devel/glib/buildlink2.mk"

BUILDLINK_TARGETS+=	liboop-buildlink

liboop-buildlink: _BUILDLINK_USE

.endif	# LIBOOP_BUILDLINK2_MK
