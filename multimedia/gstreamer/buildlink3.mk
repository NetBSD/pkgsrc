# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 08:16:09 xtraeme Exp $
#
# This Makefile fragment is included by packages that use gstreamer.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GSTREAMER_BUILDLINK3_MK:=	${GSTREAMER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gstreamer
.endif

.if !empty(GSTREAMER_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			gstreamer
BUILDLINK_DEPENDS.gstreamer+=		gstreamer>=0.6.4
BUILDLINK_PKGSRCDIR.gstreamer?=		../../multimedia/gstreamer

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"

.endif # GSTREAMER_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
