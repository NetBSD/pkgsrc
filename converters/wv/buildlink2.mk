# $NetBSD: buildlink2.mk,v 1.8 2003/12/13 23:45:12 xtraeme Exp $
#
# This Makefile fragment is included by packages that use wv.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(WV_BUILDLINK2_MK)
WV_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			wv
BUILDLINK_DEPENDS.wv?=			wv>=1.0.0
BUILDLINK_PKGSRCDIR.wv?=		../../converters/wv

EVAL_PREFIX+=	BUILDLINK_PREFIX.wv=wv
BUILDLINK_PREFIX.wv_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.wv+=	include/wv/libole2/ms-ole-summary.h
BUILDLINK_FILES.wv+=	include/wv/libole2/ms-ole.h
BUILDLINK_FILES.wv+=	include/wv/wv.h
BUILDLINK_FILES.wv+=	lib/libwv-1.0.*
BUILDLINK_FILES.wv+=	lib/libwv.*

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/libwmf/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"

BUILDLINK_TARGETS+=	wv-buildlink

wv-buildlink: _BUILDLINK_USE

.endif	# WV_BUILDLINK2_MK
