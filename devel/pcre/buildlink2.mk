# $NetBSD: buildlink2.mk,v 1.1.2.3 2002/06/21 23:00:28 jlam Exp $

.if !defined(PCRE_BUILDLINK2_MK)
PCRE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		pcre
BUILDLINK_DEPENDS.pcre?=	pcre>=3.4
BUILDLINK_PKGSRCDIR.pcre?=	../../devel/pcre

EVAL_PREFIX+=	BUILDLINK_PREFIX.pcre=pcre
BUILDLINK_PREFIX.pcre_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pcre=	include/pcre.h
BUILDLINK_FILES.pcre+=	include/pcreposix.h
BUILDLINK_FILES.pcre+=	lib/libpcre.*
BUILDLINK_FILES.pcre+=	lib/libpcreposix.*

BUILDLINK_TARGETS+=	pcre-buildlink

pcre-buildlink: _BUILDLINK_USE

.endif	# PCRE_BUILDLINK2_MK
