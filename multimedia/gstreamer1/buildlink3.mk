# $NetBSD: buildlink3.mk,v 1.1 2012/11/29 08:21:17 ryoon Exp $

BUILDLINK_TREE+=	gstreamer1

.if !defined(GSTREAMER1_BUILDLINK3_MK)
GSTREAMER1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gstreamer1+=	gstreamer1>=1.0.0
BUILDLINK_ABI_DEPENDS.gstreamer1+=	gstreamer1>=1.0.0
BUILDLINK_PKGSRCDIR.gstreamer1?=	../../multimedia/gstreamer1

pkgbase := gstreamer1
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.gstreamer1:Mgstcheck)
.include "../../devel/check/buildlink3.mk"
.endif

.include "../../devel/glib2/buildlink3.mk"
.endif # GSTREAMER1_BUILDLINK3_MK

BUILDLINK_TREE+=	-gstreamer1
