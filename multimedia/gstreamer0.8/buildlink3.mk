# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:11:01 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GSTREAMER0.8_BUILDLINK3_MK:=	${GSTREAMER0.8_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gstreamer0.8
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngstreamer0.8}
BUILDLINK_PACKAGES+=	gstreamer0.8
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gstreamer0.8

.if !empty(GSTREAMER0.8_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gstreamer0.8+=	gstreamer0.8>=0.8.11
BUILDLINK_ABI_DEPENDS.gstreamer0.8?=	gstreamer0.8>=0.8.11nb5
BUILDLINK_PKGSRCDIR.gstreamer0.8?=	../../multimedia/gstreamer0.8

PRINT_PLIST_AWK+=	/^@dirrm (include|lib)\/gstreamer-0.8(\/gst)?$$/ \
			    { print "@comment in gstreamer0.8: " $$0; next; }
.endif	# GSTREAMER0.8_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
