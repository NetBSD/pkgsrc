# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/11/04 02:56:17 rh Exp $
#
# This Makefile fragment is included by packages that use libgtop2.
#
# This file was created automatically using createbuildlink 2.2.
#

.if !defined(LIBGTOP2_BUILDLINK2_MK)
LIBGTOP2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libgtop2
BUILDLINK_DEPENDS.libgtop2?=		libgtop2>=2.0.0
BUILDLINK_PKGSRCDIR.libgtop2?=		../../devel/libgtop2

EVAL_PREFIX+=	BUILDLINK_PREFIX.libgtop2=libgtop2
BUILDLINK_PREFIX.libgtop2_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.libgtop2+=	include/libgtop-2.0/*.h
BUILDLINK_FILES.libgtop2+=	include/libgtop-2.0/glibtop/*.h
BUILDLINK_FILES.libgtop2+=	lib/libgnomesupport-2.0.*
BUILDLINK_FILES.libgtop2+=	lib/libgtop-2.0.*
BUILDLINK_FILES.libgtop2+=	lib/libgtop/include/gnomesupport.h
BUILDLINK_FILES.libgtop2+=	lib/libgtop_common-2.0.*
BUILDLINK_FILES.libgtop2+=	lib/libgtop_names-2.0.*
BUILDLINK_FILES.libgtop2+=	lib/libgtop_suid_common-2.0.*
BUILDLINK_FILES.libgtop2+=	lib/libgtop_sysdeps-2.0.*
BUILDLINK_FILES.libgtop2+=	lib/libgtop_sysdeps_suid-2.0.*
BUILDLINK_FILES.libgtop2+=	lib/pkgconfig/libgtop-2.0.pc

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"

BUILDLINK_TARGETS+=	libgtop2-buildlink

libgtop2-buildlink: _BUILDLINK_USE

.endif	# LIBGTOP2_BUILDLINK2_MK
