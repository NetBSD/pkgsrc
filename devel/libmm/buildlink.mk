# $NetBSD: buildlink.mk,v 1.1 2001/10/23 14:40:36 jlam Exp $
#
# This Makefile fragment is included by packages that use libmm.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libmm to the dependency pattern
#     for the version of libmm desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBMM_BUILDLINK_MK)
LIBMM_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libmm?=	libmm>=1.1.3
DEPENDS+=	${BUILDLINK_DEPENDS.libmm}:../../devel/libmm

EVAL_PREFIX+=		BUILDLINK_PREFIX.libmm=libmm
BUILDLINK_PREFIX.libmm_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libmm=	include/mm.h
BUILDLINK_FILES.libmm+=	lib/libmm.*

BUILDLINK_TARGETS.libmm=	libmm-buildlink
BUILDLINK_TARGETS.libmm+=	libmm-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.libmm}

BUILDLINK_CONFIG.libmm=		${BUILDLINK_PREFIX.libmm}/bin/mm-config
BUILDLINK_CONFIG_WRAPPER.libmm=	${BUILDLINK_DIR}/bin/mm-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.libmm}|${BUILDLINK_CONFIG.libmm}|g"

.if defined(USE_CONFIG_WRAPPER)
MM_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.libmm}
CONFIGURE_ENV+=		MM_CONFIG="${MM_CONFIG}"
MAKE_ENV+=		MM_CONFIG="${MM_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.libmm}
libmm-buildlink: _BUILDLINK_USE
libmm-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# LIBMM_BUILDLINK_MK
