# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/05/11 02:08:59 jlam Exp $
#
# This Makefile fragment is included by packages that use libiconv.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.iconv to the dependency pattern
#     for the version of libiconv desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(ICONV_BUILDLINK2_MK)
ICONV_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.iconv?=	libiconv>=1.5
DEPENDS+=	${BUILDLINK_DEPENDS.iconv}:../../converters/libiconv

BUILDLINK_PREFIX.iconv=		${LOCALBASE}
BUILDLINK_FILES.iconv=		include/iconv.h
BUILDLINK_FILES.iconv+=		include/libcharset.h
BUILDLINK_FILES.iconv+=		lib/libcharset.*
BUILDLINK_FILES.iconv+=		lib/libiconv.*

BUILDLINK_TARGETS+=		iconv-buildlink

iconv-buildlink: _BUILDLINK_USE

.endif	# ICONV_BUILDLINK2_MK
