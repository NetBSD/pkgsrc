# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/12/03 19:17:11 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libidn.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(LIBIDN_BUILDLINK2_MK)
LIBIDN_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libidn
BUILDLINK_DEPENDS.libidn?=		libidn>=0.3.3
BUILDLINK_PKGSRCDIR.libidn?=		../../devel/libidn

EVAL_PREFIX+=	BUILDLINK_PREFIX.libidn=libidn
BUILDLINK_PREFIX.libidn_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libidn+=	include/idn-int.h
BUILDLINK_FILES.libidn+=	include/idna.h
BUILDLINK_FILES.libidn+=	include/punycode.h
BUILDLINK_FILES.libidn+=	include/stringprep.h
BUILDLINK_FILES.libidn+=	lib/libidn.*

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/libgetopt/buildlink2.mk"

BUILDLINK_TARGETS+=	libidn-buildlink

libidn-buildlink: _BUILDLINK_USE

.endif	# LIBIDN_BUILDLINK2_MK
