# $NetBSD: buildlink.mk,v 1.1.1.1 2002/07/12 17:33:14 wiz Exp $
#
# This Makefile fragment is included by packages that use libglade2.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libglade2 to the dependency pattern
#     for the version of libglade2 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBGLADE2_BUILDLINK_MK)
LIBGLADE2_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libglade2?=	libglade2>=2.0.0
DEPENDS+=	${BUILDLINK_DEPENDS.libglade2}:../../devel/libglade2

EVAL_PREFIX+=			BUILDLINK_PREFIX.libglade2=libglade2
BUILDLINK_PREFIX.libglade2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libglade2=	include/libglade-2.0/glade/*
BUILDLINK_FILES.libglade2+=	lib/libglade-2.0.*
BUILDLINK_FILES.libglade2+=	lib/pkgconfig/libglade-2.0.pc

CPPFLAGS+=			-I${BUILDLINK_DIR}/include/libglade-2.0

.include "../../textproc/libxml2/buildlink.mk"
.include "../../x11/gtk2/buildlink.mk"

BUILDLINK_TARGETS.libglade2=	libglade2-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.libglade2}

pre-configure: ${BUILDLINK_TARGETS.libglade2}
libglade2-buildlink: _BUILDLINK_USE

.endif	# LIBGLADE2_BUILDLINK_MK
