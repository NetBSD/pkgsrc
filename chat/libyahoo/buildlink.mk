# $NetBSD: buildlink.mk,v 1.3 2002/09/20 09:51:44 jlam Exp $
#
# This Makefile fragment is included by packages that use libyahoo.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libyahoo to the dependency pattern
#     for the version of libyahoo desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBYAHOO_BUILDLINK_MK)
LIBYAHOO_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libyahoo?=	libyahoo>=0.18.4
DEPENDS+=		${BUILDLINK_DEPENDS.libyahoo}:../../chat/libyahoo

EVAL_PREFIX+=				BUILDLINK_PREFIX.libyahoo=libyahoo
BUILDLINK_PREFIX.libyahoo_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libyahoo=		include/libyahoo/*.h
BUILDLINK_FILES.libyahoo+=		lib/libyahoo.a

BUILDLINK_TRANSFORM.libyahoo=	-e "s|include/libyahoo/|include/|g"

BUILDLINK_TARGETS.libyahoo=	libyahoo-buildlink
BUILDLINK_TARGETS.libyahoo+=	libyahoo-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.libyahoo}

BUILDLINK_CONFIG.libyahoo=	${BUILDLINK_PREFIX.libyahoo}/bin/libyahoo-config
BUILDLINK_CONFIG_WRAPPER.libyahoo=	${BUILDLINK_DIR}/bin/libyahoo-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.libyahoo}|${BUILDLINK_CONFIG.libyahoo}|g"

.if defined(USE_CONFIG_WRAPPER)
LIBYAHOO_CONFIG?=	${BUILDLINK_CONFIG_WRAPPER.libyahoo}
CONFIGURE_ENV+=		LIBYAHOO_CONFIG="${LIBYAHOO_CONFIG}"
MAKE_ENV+=		LIBYAHOO_CONFIG="${LIBYAHOO_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.libyahoo}
libyahoo-buildlink: _BUILDLINK_USE
libyahoo-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# LIBYAHOO_BUILDLINK_MK
