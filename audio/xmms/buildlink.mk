# $NetBSD: buildlink.mk,v 1.6 2001/10/03 20:56:43 jlam Exp $
#
# This Makefile fragment is included by packages that use xmms.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.xmms to the dependency pattern
#     for the version of libxmms desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(XMMS_BUILDLINK_MK)
XMMS_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.xmms?=	xmms>=1.2.5
DEPENDS+=		${BUILDLINK_DEPENDS.xmms}:../../audio/xmms

EVAL_PREFIX+=		BUILDLINK_PREFIX.xmms=xmms
BUILDLINK_PREFIX.xmms_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.xmms=	include/xmms/*
BUILDLINK_FILES.xmms+=	lib/libxmms.*

.include "../../x11/gtk/buildlink.mk"

BUILDLINK_TARGETS.xmms=	xmms-buildlink
BUILDLINK_TARGETS.xmms+=xmms-buildlink-config-wrapper
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.xmms}

BUILDLINK_CONFIG.xmms=		${BUILDLINK_PREFIX.xmms}/bin/xmms-config
BUILDLINK_CONFIG_WRAPPER.xmms=	${BUILDLINK_DIR}/bin/xmms-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.xmms}|${BUILDLINK_CONFIG.xmms}|g"

.if defined(USE_CONFIG_WRAPPER)
XMMS_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.xmms}
CONFIGURE_ENV+=		XMMS_CONFIG="${XMMS_CONFIG}"
MAKE_ENV+=		XMMS_CONFIG="${XMMS_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.xmms}
xmms-buildlink: _BUILDLINK_USE
xmms-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# XMMS_BUILDLINK_MK
