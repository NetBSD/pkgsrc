# $NetBSD: buildlink3.mk,v 1.2 2006/02/05 23:10:16 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GSTREAMER0.10_BUILDLINK3_MK:=	${GSTREAMER0.10_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gstreamer0.10
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngstreamer0.10}
BUILDLINK_PACKAGES+=	gstreamer0.10

.if !empty(GSTREAMER0.10_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gstreamer0.10+=	gstreamer0.10>=0.10.1
BUILDLINK_RECOMMENDED.gstreamer0.10?=	gstreamer0.10>=0.10.2nb1
BUILDLINK_PKGSRCDIR.gstreamer0.10?=	../../multimedia/gstreamer0.10

PRINT_PLIST_AWK+=	/^@dirrm (include|lib)\/gstreamer-0.10(\/gst)?$$/ \
			    { print "@comment in gstreamer0.10: " $$0; next; }
.endif	# GSTREAMER0.10_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
