# $NetBSD: buildlink2.mk,v 1.2 2002/10/26 18:45:14 seb Exp $
#
# This Makefile fragment is included by packages that use freewais-sf.
#
# This file was created automatically using createbuildlink 2.2.
#

.if !defined(FREEWAIS_SF_BUILDLINK2_MK)
FREEWAIS_SF_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			freewais-sf
BUILDLINK_DEPENDS.freewais-sf?=		freewais-sf>=2.2.12
BUILDLINK_PKGSRCDIR.freewais-sf?=	../../net/freewais-sf

EVAL_PREFIX+=	BUILDLINK_PREFIX.freewais-sf=freewais-sf
BUILDLINK_PREFIX.freewais-sf_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.freewais-sf+=	include/wais.h
BUILDLINK_FILES.freewais-sf+=	lib/libwais.*

BUILDLINK_TARGETS+=	freewais-sf-buildlink

freewais-sf-buildlink: _BUILDLINK_USE

.endif	# FREEWAIS_SF_BUILDLINK2_MK
