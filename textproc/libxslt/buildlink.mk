# $NetBSD: buildlink.mk,v 1.1.1.1 2001/11/23 08:34:25 martti Exp $
#
# This Makefile fragment is included by packages that use libxslt.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libxslt to the dependency pattern
#     for the version of libxslt desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBXSLT_BUILDLINK_MK)
LIBXSLT_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libxslt?=	libxslt>=1.0.7
DEPENDS+=	${BUILDLINK_DEPENDS.libxslt}:../../textproc/libxslt

EVAL_PREFIX+=			BUILDLINK_PREFIX.libxslt=libxslt
BUILDLINK_PREFIX.libxslt_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libxslt=	include/breakpoint/*
BUILDLINK_FILES.libxslt+=	include/libexslt/*
BUILDLINK_FILES.libxslt+=	include/libxslt/*
BUILDLINK_FILES.libxslt+=	lib/libexslt.*
BUILDLINK_FILES.libxslt+=	lib/libxslt.*
BUILDLINK_FILES.libxslt+=	lib/libxsltbreakpoint.*
BUILDLINK_FILES.libxslt+=	lib/xsltConf.sh

.include "../../textproc/libxml2/buildlink.mk"

BUILDLINK_TARGETS.libxslt=	libxslt-buildlink
BUILDLINK_TARGETS.libxslt+=	libxslt-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.libxslt}

BUILDLINK_CONFIG.libxslt=	\
		${BUILDLINK_PREFIX.libxslt}/bin/xslt-config
BUILDLINK_CONFIG_WRAPPER.libxslt=	\
		${BUILDLINK_DIR}/bin/xslt-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.libxslt}|${BUILDLINK_CONFIG.libxslt}|g"

.if defined(USE_CONFIG_WRAPPER)
XSLT_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.libxslt}
CONFIGURE_ENV+=		XSLT_CONFIG="${XSLT_CONFIG}"
MAKE_ENV+=		XSLT_CONFIG="${XSLT_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.libxslt}
libxslt-buildlink: _BUILDLINK_USE
libxslt-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# LIBXSLT_BUILDLINK_MK
