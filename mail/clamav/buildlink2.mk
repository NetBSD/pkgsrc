# $NetBSD: buildlink2.mk,v 1.1 2003/12/08 05:46:23 grant Exp $
#
# This Makefile fragment is included by packages that use clamav.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(CLAMAV_BUILDLINK2_MK)
CLAMAV_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			clamav
BUILDLINK_DEPENDS.clamav?=		clamav>=0.60nb1
BUILDLINK_PKGSRCDIR.clamav?=		../../mail/clamav

EVAL_PREFIX+=	BUILDLINK_PREFIX.clamav=clamav
BUILDLINK_PREFIX.clamav_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.clamav+=	include/clamav.h
BUILDLINK_FILES.clamav+=	lib/libclamav.*

.include "../../devel/zlib/buildlink2.mk"
.include "../../archivers/bzip2/buildlink2.mk"

BUILDLINK_TARGETS+=	clamav-buildlink

clamav-buildlink: _BUILDLINK_USE

.endif	# CLAMAV_BUILDLINK2_MK
