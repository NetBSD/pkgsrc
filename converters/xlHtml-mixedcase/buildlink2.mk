# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:22:03 jlam Exp $

.if !defined(XLHTML_BUILDLINK2_MK)
XLHTML_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		xlHtml
BUILDLINK_DEPENDS.xlHtml?=	xlHtml>=0.2.8
BUILDLINK_PKGSRCDIR.xlHtml?=	../../databases/xlHtml

EVAL_PREFIX+=			BUILDLINK_PREFIX.xlHtml=xlHtml
BUILDLINK_PREFIX.xlHtml_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.xlHtml=		include/cole/*
BUILDLINK_FILES.xlHtml+=	lib/libcole.*

BUILDLINK_TARGETS+=	xlHtml-buildlink

xlHtml-buildlink: _BUILDLINK_USE

.endif	# XLHTML_BUILDLINK2_MK
