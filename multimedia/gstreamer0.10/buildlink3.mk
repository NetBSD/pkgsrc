# $NetBSD: buildlink3.mk,v 1.7 2007/02/08 21:27:14 drochner Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GSTREAMER0.10_BUILDLINK3_MK:=	${GSTREAMER0.10_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gstreamer0.10
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngstreamer0.10}
BUILDLINK_PACKAGES+=	gstreamer0.10
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gstreamer0.10

.if !empty(GSTREAMER0.10_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gstreamer0.10+=	gstreamer0.10>=0.10.1
BUILDLINK_ABI_DEPENDS.gstreamer0.10?=	gstreamer0.10>=0.10.2nb1
BUILDLINK_PKGSRCDIR.gstreamer0.10?=	../../multimedia/gstreamer0.10

PRINT_PLIST_AWK+=	/^@dirrm (include|lib)\/gstreamer-0.10(\/gst)?$$/ \
			    { print "@comment in gstreamer0.10: " $$0; next; }
.endif	# GSTREAMER0.10_BUILDLINK3_MK

.if !defined(PKG_BUILD_OPTIONS.gstreamer)
PKG_BUILD_OPTIONS.gstreamer!= \
	cd ${BUILDLINK_PKGSRCDIR.gstreamer0.10} && \
	${MAKE} show-var ${MAKEFLAGS} VARNAME=PKG_OPTIONS
.endif

.if !empty(PKG_BUILD_OPTIONS.gstreamer:Mgstcheck)
.include "../../devel/check/buildlink3.mk"
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
