# $NetBSD: buildlink3.mk,v 1.1 2004/02/15 20:19:00 wiz Exp $
#
# This Makefile fragment is included by packages that use wv.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
WV_BUILDLINK3_MK:=	${WV_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	wv
.endif

.if !empty(WV_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			wv
BUILDLINK_DEPENDS.wv+=			wv>=1.0.0
BUILDLINK_PKGSRCDIR.wv?=		../../converters/wv

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/libwmf/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.endif # WV_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
