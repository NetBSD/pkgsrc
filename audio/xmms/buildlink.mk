# $NetBSD: buildlink.mk,v 1.2 2001/08/16 03:06:31 hubertf Exp $
#
# This Makefile fragment is included by packages that use libxmms.
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
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.xmms}

pre-configure: ${BUILDLINK_TARGETS.xmms}
xmms-buildlink: _BUILDLINK_USE

.endif	# XMMS_BUILDLINK_MK
