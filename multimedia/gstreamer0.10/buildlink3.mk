# $NetBSD: buildlink3.mk,v 1.13 2011/04/22 13:42:19 obache Exp $

BUILDLINK_TREE+=	gstreamer0.10

.if !defined(GSTREAMER0.10_BUILDLINK3_MK)
GSTREAMER0.10_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gstreamer0.10+=	gstreamer0.10>=0.10.1
BUILDLINK_ABI_DEPENDS.gstreamer0.10?=	gstreamer0.10>=0.10.32nb1
BUILDLINK_PKGSRCDIR.gstreamer0.10?=	../../multimedia/gstreamer0.10

pkgbase := gstreamer0.10
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.gstreamer0.10:Mgstcheck)
.include "../../devel/check/buildlink3.mk"
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

# PR#44108 gst-inspect hang up on DragonFly BSD.
.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "DragonFly"
ALL_ENV+=	GST_REGISTRY_FORK=no
.endif

.endif # GSTREAMER0.10_BUILDLINK3_MK

BUILDLINK_TREE+=	-gstreamer0.10
