# $NetBSD: buildlink3.mk,v 1.3 2004/03/18 09:12:13 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GSTREAMER_BUILDLINK3_MK:=	${GSTREAMER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gstreamer
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngstreamer}
BUILDLINK_PACKAGES+=	gstreamer

.if !empty(GSTREAMER_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gstreamer+=	gstreamer>=0.6.4
BUILDLINK_PKGSRCDIR.gstreamer?=	../../multimedia/gstreamer
.endif	# GSTREAMER_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
