# $NetBSD: buildlink.mk,v 1.3 2001/06/11 01:59:33 jlam Exp $
#
# This Makefile fragment is included by packages that use libiconv.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define ICONV_REQD to the version of libiconv desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(ICONV_BUILDLINK_MK)
ICONV_BUILDLINK_MK=	# defined

ICONV_REQD?=		1.5
DEPENDS+=		libiconv>=${ICONV_REQD}:../../converters/libiconv

BUILDLINK_PREFIX.iconv=		${LOCALBASE}
BUILDLINK_FILES.iconv=		include/iconv.h
BUILDLINK_FILES.iconv+=		include/libcharset.h
BUILDLINK_FILES.iconv+=		lib/libcharset.*
BUILDLINK_FILES.iconv+=		lib/libiconv.*

BUILDLINK_TARGETS.iconv=	iconv-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.iconv}

pre-configure: ${BUILDLINK_TARGETS.iconv}
iconv-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# ICONV_BUILDLINK_MK
