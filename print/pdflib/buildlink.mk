# $NetBSD: buildlink.mk,v 1.3 2001/08/17 21:14:14 jlam Exp $
#
# This Makefile fragment is included by packages that use pdflib.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.pdflib to the dependency pattern
#     for the version of pdflib desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(PDFLIB_BUILDLINK_MK)
PDFLIB_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.pdflib?=	pdflib>=4.0.1
DEPENDS+=	${BUILDLINK_DEPENDS.pdflib}:../../print/pdflib

EVAL_PREFIX+=				BUILDLINK_PREFIX.pdflib=pdflib
BUILDLINK_PREFIX.pdflib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pdflib=			include/pdflib.h
BUILDLINK_FILES.pdflib+=		lib/libpdf.*

.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"

BUILDLINK_TARGETS.pdflib=	pdflib-buildlink
BUILDLINK_TARGETS.pdflib+=	pdflib-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.pdflib}

BUILDLINK_CONFIG.pdflib=	${BUILDLINK_PREFIX.pdflib}/bin/pdflib-config
BUILDLINK_CONFIG_WRAPPER.pdflib=	${BUILDLINK_DIR}/bin/pdflib-config

.if defined(USE_CONFIG_WRAPPER)
PDFLIB_CONFIG?=			${BUILDLINK_CONFIG_WRAPPER.pdflib}
CONFIGURE_ENV+=			PDFLIB_CONFIG="${PDFLIB_CONFIG}"
MAKE_ENV+=			PDFLIB_CONFIG="${PDFLIB_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.pdflib}
pdflib-buildlink: _BUILDLINK_USE
pdflib-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# PDFLIB_BUILDLINK_MK
