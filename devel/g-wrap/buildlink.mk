# $NetBSD: buildlink.mk,v 1.1 2002/08/23 11:26:14 mjl Exp $
#
# This Makefile fragment is included by packages that use g-wrap.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.g-wrap to the dependency pattern
#     for the version of g-wrap desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(G_WRAP_BUILDLINK_MK)
G_WRAP_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.g-wrap?=	g-wrap>=1.2.1
DEPENDS+=	${BUILDLINK_DEPENDS.g-wrap}:../../devel/g-wrap

EVAL_PREFIX+=			BUILDLINK_PREFIX.g-wrap=g-wrap
BUILDLINK_PREFIX.g-wrap_DEFAULT=${X11PREFIX}
BUILDLINK_FILES.g-wrap+=	include/g-wrap-runtime-guile.h
BUILDLINK_FILES.g-wrap+=	lib/libg-wrap*

BUILDLINK_TARGETS.g-wrap=	g-wrap-buildlink
BUILDLINK_TARGETS.g-wrap+=	g-wrap-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.g-wrap}

BUILDLINK_CONFIG.g-wrap=	${BUILDLINK_PREFIX.g-wrap}/bin/g-wrap-config
BUILDLINK_CONFIG_WRAPPER.g-wrap=${BUILDLINK_DIR}/bin/g-wrap-config

.if defined(USE_CONFIG_WRAPPER)
G_WRAP_CONFIG?=	${BUILDLINK_CONFIG_WRAPPER.g-wrap}
CONFIGURE_ENV+=		G_WRAP_CONFIG="${G_WRAP_CONFIG}"
MAKE_ENV+=		G_WRAP_CONFIG="${G_WRAP_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.g-wrap}
g-wrap-buildlink: _BUILDLINK_USE
g-wrap-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# G_WRAP_BUILDLINK_MK
