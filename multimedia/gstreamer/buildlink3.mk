# $NetBSD: buildlink3.mk,v 1.4 2004/03/26 02:27:47 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GSTREAMER_BUILDLINK3_MK:=	${GSTREAMER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gstreamer
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngstreamer}
BUILDLINK_PACKAGES+=	gstreamer

.if !empty(GSTREAMER_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gstreamer+=	gstreamer>=0.6.4
BUILDLINK_RECOMMENDED.gstreamer?=	gstreamer>=0.6.4nb2
BUILDLINK_PKGSRCDIR.gstreamer?=	../../multimedia/gstreamer
.endif	# GSTREAMER_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
