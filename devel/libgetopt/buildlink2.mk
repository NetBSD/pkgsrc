# $NetBSD: buildlink2.mk,v 1.3 2004/03/29 05:05:35 jlam Exp $

.if !defined(GETOPT_BUILDLINK2_MK)
GETOPT_BUILDLINK2_MK=	# defined

BUILDLINK_PKGBASE.getopt?=	libgetopt
BUILDLINK_DEPENDS.getopt?=	libgetopt>=1.3
BUILDLINK_PKGSRCDIR.getopt?=	../../devel/libgetopt

.if exists(/usr/include/getopt.h)
_NEED_GETOPT=		NO
.else
_NEED_GETOPT=		YES
.endif

.if ${_NEED_GETOPT} == "NO"
BUILDLINK_PREFIX.getopt=	/usr
BUILDLINK_FILES.getopt=		include/getopt.h
LIBGETOPT=			# empty
.else
BUILDLINK_PACKAGES+=		getopt
EVAL_PREFIX+=	BUILDLINK_PREFIX.getopt=libgetopt
BUILDLINK_PREFIX.getopt_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.getopt=		include/getopt.h
BUILDLINK_FILES.getopt+=	lib/libgetopt.*
BUILDLINK_FILES.getopt+=	lib/libgetopt_pic.a
LIBGETOPT=			-lgetopt
.endif

CONFIGURE_ENV+=			LIBGETOPT="${LIBGETOPT}"
MAKE_ENV+=			LIBGETOPT="${LIBGETOPT}"

BUILDLINK_TARGETS+=		getopt-buildlink

getopt-buildlink: _BUILDLINK_USE

.endif	# GETOPT_BUILDLINK2_MK
