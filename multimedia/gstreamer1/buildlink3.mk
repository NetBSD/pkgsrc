# $NetBSD: buildlink3.mk,v 1.6 2022/06/28 11:34:55 wiz Exp $

BUILDLINK_TREE+=	gstreamer1

.if !defined(GSTREAMER1_BUILDLINK3_MK)
GSTREAMER1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gstreamer1+=	gstreamer1>=1.18.4
BUILDLINK_ABI_DEPENDS.gstreamer1?=	gstreamer1>=1.20.2nb2
BUILDLINK_PKGSRCDIR.gstreamer1?=	../../multimedia/gstreamer1

pkgbase := gstreamer1
.include "../../mk/pkg-build-options.mk"

.include "../../devel/glib2/buildlink3.mk"
.endif # GSTREAMER1_BUILDLINK3_MK

BUILDLINK_TREE+=	-gstreamer1
