# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/05/11 02:09:25 jlam Exp $
#
# This Makefile fragment is included by packages that use libxml.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libxml to the dependency pattern
#     for the version of libxml desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(LIBXML_BUILDLINK2_MK)
LIBXML_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.libxml?=	libxml>=1.8.11
DEPENDS+=	${BUILDLINK_DEPENDS.libxml}:../../textproc/libxml

BUILDLINK_PREFIX.libxml=	${LOCALBASE}
BUILDLINK_FILES.libxml=		include/gnome-xml/*
BUILDLINK_FILES.libxml+=	lib/libxml.*
BUILDLINK_FILES.libxml+=	lib/xmlConf.sh

.include "../../devel/zlib/buildlink2.mk"

BUILDLINK_TARGETS+=		libxml-buildlink

libxml-buildlink: _BUILDLINK_USE

.endif	# LIBXML_BUILDLINK2_MK
