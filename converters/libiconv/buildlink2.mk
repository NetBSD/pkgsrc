# $NetBSD: buildlink2.mk,v 1.1.2.3 2002/06/21 23:00:26 jlam Exp $

.if !defined(ICONV_BUILDLINK2_MK)
ICONV_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		iconv
BUILDLINK_DEPENDS.iconv?=	libiconv>=1.5
BUILDLINK_PKGSRCDIR.iconv?=	../../converters/libiconv

EVAL_PREFIX+=	BUILDLINK_PREFIX.iconv=libiconv
BUILDLINK_PREFIX.iconv_DEFAULT=		${LOCALBASE}
BUILDLINK_FILES.iconv=		include/iconv.h
BUILDLINK_FILES.iconv+=		include/libcharset.h
BUILDLINK_FILES.iconv+=		lib/libcharset.*
BUILDLINK_FILES.iconv+=		lib/libiconv.*

BUILDLINK_TARGETS+=		iconv-buildlink

iconv-buildlink: _BUILDLINK_USE

.endif	# ICONV_BUILDLINK2_MK
