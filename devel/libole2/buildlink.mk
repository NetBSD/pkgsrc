# $NetBSD: buildlink.mk,v 1.3 2001/11/11 20:00:13 damon Exp $
#
# This Makefile fragment is included by packages that use libole2.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libole2 to the dependency pattern
#     for the version of libole2 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBOLE2_BUILDLINK_MK)
LIBOLE2_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libole2?=	libole2>=0.2.4
DEPENDS+=	${BUILDLINK_DEPENDS.libole2}:../../devel/libole2

EVAL_PREFIX+=		BUILDLINK_PREFIX.libole2=libole2
BUILDLINK_PREFIX.libole2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libole2+=	include/libole2/*
BUILDLINK_FILES.libole2+=	lib/libgnomeole2.*

.include "../../devel/glib/buildlink.mk"

BUILDLINK_TARGETS.libole2=	libole2-buildlink
BUILDLINK_TARGETS.libole2+=	libole2-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.libole2}

BUILDLINK_CONFIG.libole2=	${BUILDLINK_PREFIX.libole2}/lib/libole2Conf.sh
BUILDLINK_CONFIG_WRAPPER.libole2=	${BUILDLINK_DIR}/lib/libole2Conf.sh
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.libole2}|${BUILDLINK_CONFIG.libole2}|g"

.if defined(USE_CONFIG_WRAPPER)
LIBOLE2_CONFIG?=	${BUILDLINK_CONFIG_WRAPPER.libole2}
CONFIGURE_ENV+=		LIBOLE2_CONFIG="${LIBOLE2_CONFIG}"
MAKE_ENV+=		LIBOLE2_CONFIG="${LIBOLE2_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.libole2}
libole2-buildlink: _BUILDLINK_USE
libole2-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# LIBOLE2_BUILDLINK_MK
