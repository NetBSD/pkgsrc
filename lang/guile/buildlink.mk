# $NetBSD: buildlink.mk,v 1.1 2002/04/12 13:00:27 jlam Exp $
#
# This Makefile fragment is included by packages that use guile.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.guile to the dependency pattern
#     for the version of guile desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GUILE_BUILDLINK_MK)
GUILE_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.guile?=	guile>=1.4
DEPENDS+=		${BUILDLINK_DEPENDS.guile}:../../lang/guile

EVAL_PREFIX+=		BUILDLINK_PREFIX.guile=guile
BUILDLINK_PREFIX.guile_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.guile+=	include/guile/*
BUILDLINK_FILES.guile+=	include/guile-readline/*
BUILDLINK_FILES.guile+=	include/libguile.h
BUILDLINK_FILES.guile+=	include/libguile/*
BUILDLINK_FILES.guile+=	lib/libguile.*
BUILDLINK_FILES.guile+=	lib/libguilereadline.*

USE_GNU_READLINE=	# defined

.include "../../devel/readline/buildlink.mk"

BUILDLINK_TARGETS.guile=	guile-buildlink
BUILDLINK_TARGETS.guile+=	guile-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.guile}

BUILDLINK_CONFIG.guile=		${BUILDLINK_PREFIX.guile}/bin/guile-config
BUILDLINK_CONFIG_WRAPPER.guile=	${BUILDLINK_DIR}/bin/guile-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.guile}|${BUILDLINK_CONFIG.guile}|g"

.if defined(USE_CONFIG_WRAPPER)
GUILE_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.guile}
CONFIGURE_ENV+=		GUILE_CONFIG="${GUILE_CONFIG}"
MAKE_ENV+=		GUILE_CONFIG="${GUILE_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.guile}
guile-buildlink: _BUILDLINK_USE
guile-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# GUILE_BUILDLINK_MK
