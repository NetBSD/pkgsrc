# $NetBSD: buildlink2.mk,v 1.3 2004/02/10 00:17:29 jlam Exp $
#
# This Makefile fragment is included by packages that use gss.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(GSS_BUILDLINK2_MK)
GSS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gss
BUILDLINK_DEPENDS.gss?=		gss>=0.0.6nb1
BUILDLINK_PKGSRCDIR.gss?=		../../security/gss

EVAL_PREFIX+=	BUILDLINK_PREFIX.gss=gss
BUILDLINK_PREFIX.gss_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gss+=	include/gss.h
BUILDLINK_FILES.gss+=	include/gss/api.h
BUILDLINK_FILES.gss+=	include/gss/ext.h
BUILDLINK_FILES.gss+=	lib/libgss.*

BUILDLINK_TARGETS+=	gss-buildlink

gss-buildlink: _BUILDLINK_USE

.endif	# GSS_BUILDLINK2_MK
