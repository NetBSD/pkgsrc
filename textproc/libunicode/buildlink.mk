# $NetBSD: buildlink.mk,v 1.1 2001/10/06 12:43:08 rh Exp $
#
# This Makefile fragment is included by packages that use libunicode.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gkd-pixbuf to the dependency version
#     for the version of libunicode desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBUNICODE_BUILDLINK_MK)
LIBUNICODE_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libunicode?=	libunicode>=0.4
DEPENDS+=	${BUILDLINK_DEPENDS.libunicode}:../../textproc/libunicode

EVAL_PREFIX+=			BUILDLINK_PREFIX.libunicode=libunicode
BUILDLINK_PREFIX.libunicode_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libunicode=	include/unicode.h
BUILDLINK_FILES.libunicode+=	lib/libunicode.*

BUILDLINK_TARGETS.libunicode=	libunicode-buildlink
BUILDLINK_TARGETS.libunicode+=	libunicode-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.libunicode}

BUILDLINK_CONFIG.libunicode=	\
			${BUILDLINK_PREFIX.libunicode}/bin/unicode-config
BUILDLINK_CONFIG_WRAPPER.libunicode=	\
			${BUILDLINK_DIR}/bin/unicode-config
REPLACE_BUILDLINK_SED+=		\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.libunicode}|${BUILDLINK_CONFIG.libunicode}|g"

.if defined(USE_CONFIG_WRAPPER)
LIBUNICODE_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.libunicode}
CONFIGURE_ENV+=			LIBUNICODE_CONFIG="${LIBUNICODE_CONFIG}"
MAKE_ENV+=			LIBUNICODE_CONFIG="${LIBUNICODE_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.libunicode}
libunicode-buildlink: _BUILDLINK_USE
libunicode-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# LIBUNICODE_BUILDLINK_MK
