# $NetBSD: buildlink3.mk,v 1.4 2021/11/15 22:53:59 wiz Exp $

BUILDLINK_TREE+=	gstreamer1

.if !defined(GSTREAMER1_BUILDLINK3_MK)
GSTREAMER1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gstreamer1+=	gstreamer1>=1.18.4
BUILDLINK_ABI_DEPENDS.gstreamer1?=	gstreamer1>=1.18.5
BUILDLINK_PKGSRCDIR.gstreamer1?=	../../multimedia/gstreamer1

pkgbase := gstreamer1
.include "../../mk/pkg-build-options.mk"

.include "../../devel/check/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # GSTREAMER1_BUILDLINK3_MK

BUILDLINK_TREE+=	-gstreamer1
