# $NetBSD: buildlink.mk,v 1.3 2001/08/16 04:25:23 zuntum Exp $
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

.include "../../audio/esound/buildlink.mk"
.include "../../audio/libmikmod/buildlink.mk"
.include "../../audio/libvorbis/buildlink.mk"
.include "../../graphics/Mesa/buildlink.mk"
.include "../../textproc/libxml/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"

BUILDLINK_TARGETS.xmms=	xmms-buildlink
BUILDLINK_TARGETS.xmms+=xmms-buildlink-config-wrapper
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.xmms}

BUILDLINK_CONFIG.xmms=		${BUILDLINK_PREFIX.xmms}/bin/xmms-config
BUILDLINK_CONFIG_WRAPPER.xmms=	${BUILDLINK_DIR}/bin/xmms-config

.if defined(USE_CONFIG_WRAPPER) && defined(GNU_CONFIGURE)
XMMS_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.xmms}
CONFIGURE_ENV+=		XMMS_CONFIG="${XMMS_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.xmms}
xmms-buildlink: _BUILDLINK_USE
xmms-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# XMMS_BUILDLINK_MK
