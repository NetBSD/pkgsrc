# $NetBSD: buildlink2.mk,v 1.1 2002/10/06 13:59:22 wiz Exp $
#

.if !defined(LIBGTOP_BUILDLINK2_MK)
LIBGTOP_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libgtop
BUILDLINK_DEPENDS.libgtop?=		libgtop>=1.0.12nb3
BUILDLINK_PKGSRCDIR.libgtop?=		../../devel/libgtop

EVAL_PREFIX+=	BUILDLINK_PREFIX.libgtop=libgtop
BUILDLINK_PREFIX.libgtop_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.libgtop+=	include/glibtop.h
BUILDLINK_FILES.libgtop+=	include/glibtop/*.h
BUILDLINK_FILES.libgtop+=	include/glibtop_machine.h
BUILDLINK_FILES.libgtop+=	include/glibtop_server.h
BUILDLINK_FILES.libgtop+=	include/glibtop_suid.h
BUILDLINK_FILES.libgtop+=	lib/libgtop-features.def
BUILDLINK_FILES.libgtop+=	lib/libgtop.*
BUILDLINK_FILES.libgtop+=	lib/libgtopConf.sh
BUILDLINK_FILES.libgtop+=	lib/libgtop_common.*
BUILDLINK_FILES.libgtop+=	lib/libgtop_names.*
BUILDLINK_FILES.libgtop+=	lib/libgtop_suid_common.*
BUILDLINK_FILES.libgtop+=	lib/libgtop_sysdeps.*
BUILDLINK_FILES.libgtop+=	lib/libgtop_sysdeps_suid.*

BUILDLINK_TARGETS+=	libgtop-buildlink

libgtop-buildlink: _BUILDLINK_USE

.endif	# LIBGTOP_BUILDLINK2_MK
