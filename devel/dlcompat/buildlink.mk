# $NetBSD: buildlink.mk,v 1.1.1.1.2.2 2002/06/23 18:44:04 jlam Exp $
#
# This Makefile fragment is included by packages that use dlcompat (libdl).
#
# To use this Makefile fragment, simply:
#
# (1) Include this Makefile fragment in the package Makefile,
# (2) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (3) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(DLCOMPAT_BUILDLINK_MK)
DLCOMPAT_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.dlcompat?=	dlcompat>=20020508
DEPENDS+=		${BUILDLINK_DEPENDS.dlcompat}:../../devel/dlcompat

EVAL_PREFIX+=				BUILDLINK_PREFIX.dlcompat=dlcompat
BUILDLINK_PREFIX.dlcompat_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.dlcompat=		include/dlfcn.h
BUILDLINK_FILES.dlcompat+=		lib/libdl.*

BUILDLINK_TARGETS.dlcompat+=		dlcompat-buildlink
BUILDLINK_TARGETS+=			${BUILDLINK_TARGETS.dlcompat}

pre-configure: ${BUILDLINK_TARGETS.dlcompat}
dlcompat-buildlink: _BUILDLINK_USE

.endif  # DLCOMPAT_BUILDLINK_MK
