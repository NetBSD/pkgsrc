# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/01/22 11:28:23 markd Exp $
#
# This Makefile fragment is included by packages that use wv2.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(WV2_BUILDLINK2_MK)
WV2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			wv2
BUILDLINK_DEPENDS.wv2?=		wv2>=0.2.1
BUILDLINK_PKGSRCDIR.wv2?=		../../converters/wv2

EVAL_PREFIX+=	BUILDLINK_PREFIX.wv2=wv2
BUILDLINK_PREFIX.wv2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.wv2+=	include/wv2/*.h
BUILDLINK_FILES.wv2+=	lib/libwv2.*

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/libgsf/buildlink2.mk"

BUILDLINK_TARGETS+=	wv2-buildlink

wv2-buildlink: _BUILDLINK_USE

.endif	# WV2_BUILDLINK2_MK
