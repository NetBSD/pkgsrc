# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:25:03 joerg Exp $

BUILDLINK_TREE+=	gstreamer0.10

.if !defined(GSTREAMER0.10_BUILDLINK3_MK)
GSTREAMER0.10_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gstreamer0.10+=	gstreamer0.10>=0.10.1
BUILDLINK_ABI_DEPENDS.gstreamer0.10?=	gstreamer0.10>=0.10.2nb1
BUILDLINK_PKGSRCDIR.gstreamer0.10?=	../../multimedia/gstreamer0.10

PRINT_PLIST_AWK+=	/^@dirrm (include|lib)\/gstreamer-0.10(\/gst)?$$/ \
			    { print "@comment in gstreamer0.10: " $$0; next; }

pkgbase := gstreamer0.10
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.gstreamer0.10:Mgstcheck)
.include "../../devel/check/buildlink3.mk"
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # GSTREAMER0.10_BUILDLINK3_MK

BUILDLINK_TREE+=	-gstreamer0.10
