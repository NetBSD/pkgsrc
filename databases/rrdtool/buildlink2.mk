# $NetBSD: buildlink2.mk,v 1.1 2003/02/16 23:08:55 seb Exp $
#
# This Makefile fragment is included by packages that use rrdtool.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(RRDTOOL_BUILDLINK2_MK)
RRDTOOL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			rrdtool
BUILDLINK_DEPENDS.rrdtool?=		rrdtool>=1.0.40
BUILDLINK_PKGSRCDIR.rrdtool?=		../../databases/rrdtool

EVAL_PREFIX+=	BUILDLINK_PREFIX.rrdtool=rrdtool
BUILDLINK_PREFIX.rrdtool_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.rrdtool+=	include/rrd.h
BUILDLINK_FILES.rrdtool+=	lib/librrd.*

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/gd/buildlink2.mk"
.include "../../www/cgilib/buildlink2.mk"

BUILDLINK_TARGETS+=	rrdtool-buildlink

rrdtool-buildlink: _BUILDLINK_USE

.endif	# RRDTOOL_BUILDLINK2_MK
