# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/05/11 02:09:26 jlam Exp $
#
# This Makefile fragment is included by packages that use libxml2.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libxml2 to the dependency pattern
#     for the version of libxml2 desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(LIBXML2_BUILDLINK2_MK)
LIBXML2_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.libxml2?=	libxml2>=2.4.2
DEPENDS+=	${BUILDLINK_DEPENDS.libxml2}:../../textproc/libxml2

BUILDLINK_PREFIX.libxml2=	${LOCALBASE}
BUILDLINK_FILES.libxml2=	include/libxml2/libxml/*
BUILDLINK_FILES.libxml2+=	lib/libxml2.*
BUILDLINK_FILES.libxml2+=	lib/xml2Conf.sh

.include "../../devel/zlib/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"

BUILDLINK_TARGETS+=	libxml2-buildlink

libxml2-buildlink: _BUILDLINK_USE

.endif	# LIBXML2_BUILDLINK2_MK
