# $NetBSD: buildlink.mk,v 1.3 2002/07/12 15:19:07 wiz Exp $
#
# This Makefile fragment is included by packages that use linc.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.linc to the dependency pattern
#     for the version of linc desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LINC_BUILDLINK_MK)
LINC_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.linc?=	linc>=0.5.0
DEPENDS+=	${BUILDLINK_DEPENDS.linc}:../../net/linc

EVAL_PREFIX+=		BUILDLINK_PREFIX.linc=linc
BUILDLINK_PREFIX.linc_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.linc=	include/linc-1.0/linc/*
BUILDLINK_FILES.linc+=	lib/liblinc.*

.include "../../devel/pkgconfig/buildlink.mk"
.include "../../devel/glib2/buildlink.mk"

BUILDLINK_TARGETS.linc=	linc-buildlink
BUILDLINK_TARGETS.linc+=linc-buildlink-config-wrapper
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.linc}
BUILDLINK_TARGETS+=	${BUILDLINK_PKG_CONFIG}

BUILDLINK_CONFIG.linc=${BUILDLINK_PREFIX.linc}/bin/linc-config
BUILDLINK_CONFIG_WRAPPER.linc=${BUILDLINK_DIR}/bin/linc-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.linc}|${BUILDLINK_CONFIG.linc}|g"

.if defined(USE_CONFIG_WRAPPER)
LINC_CONFIG?=	${BUILDLINK_CONFIG_WRAPPER.linc}
CONFIGURE_ENV+=	LINC_CONFIG="${LINC_CONFIG}"
MAKE_ENV+=	LINC_CONFIG="${LINC_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS}
linc-buildlink: _BUILDLINK_USE
linc-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# LINC_BUILDLINK_MK
