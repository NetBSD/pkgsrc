# $NetBSD: buildlink2.mk,v 1.1 2003/05/09 07:33:31 agc Exp $
#
# This Makefile fragment is included by packages that use libutf.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(LIBUTF_BUILDLINK2_MK)
LIBUTF_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libutf
BUILDLINK_DEPENDS.libutf?=		libutf>=2.10nb1
BUILDLINK_PKGSRCDIR.libutf?=		../../misc/libutf

EVAL_PREFIX+=	BUILDLINK_PREFIX.libutf=libutf
BUILDLINK_PREFIX.libutf_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libutf+=	include/ure.h
BUILDLINK_FILES.libutf+=	include/utf.h
BUILDLINK_FILES.libutf+=	lib/libutf.*

BUILDLINK_TARGETS+=	libutf-buildlink

libutf-buildlink: _BUILDLINK_USE

.endif	# LIBUTF_BUILDLINK2_MK
