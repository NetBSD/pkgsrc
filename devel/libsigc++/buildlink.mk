# $NetBSD: buildlink.mk,v 1.3 2002/09/11 21:29:28 wiz Exp $
#
# This Makefile fragment is included by packages that use libsigc++.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libsigc++ to the dependency version
#     for the version of libsigc++ desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBSIGCXX_BUILDLINK_MK)
LIBSIGCXX_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libsigcxx?=	libsigc++>=1.0.4
DEPENDS+=	${BUILDLINK_DEPENDS.libsigcxx}:../../devel/libsigc++

EVAL_PREFIX+=			BUILDLINK_PREFIX.libsigcxx=libsigc++
BUILDLINK_PREFIX.libsigcxx_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libsigcxx=	include/sigc++-1.0/sigc++/*
BUILDLINK_FILES.libsigcxx+=	lib/sigc++-1.0/include/sigc++config.h
BUILDLINK_FILES.libsigcxx+=	lib/libsigc.*

BUILDLINK_TARGETS.libsigcxx=	libsigcxx-buildlink
BUILDLINK_TARGETS.libsigcxx+=	libsigcxx-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.libsigcxx}

BUILDLINK_CONFIG.libsigcxx=	\
			${BUILDLINK_PREFIX.libsigcxx}/bin/sigc-config
BUILDLINK_CONFIG_WRAPPER.libsigcxx=	\
			${BUILDLINK_DIR}/bin/sigc-config
REPLACE_BUILDLINK_SED+=		\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.libsigcxx}|${BUILDLINK_CONFIG.libsigcxx}|g"

.if defined(USE_CONFIG_WRAPPER)
SIGC_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.libsigcxx}
CONFIGURE_ENV+=		SIGC_CONFIG="${SIGC_CONFIG}"
MAKE_ENV+=		SIGC_CONFIG="${SIGC_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.libsigcxx}
libsigcxx-buildlink: _BUILDLINK_USE
libsigcxx-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# LIBSIGCXX_BUILDLINK_MK
