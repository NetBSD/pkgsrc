# $NetBSD: buildlink3.mk,v 1.20.2.1 2012/10/03 12:08:52 spz Exp $

BUILDLINK_TREE+=	farsight2

.if !defined(FARSIGHT2_BUILDLINK3_MK)
FARSIGHT2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.farsight2+=	farsight2>=0.0.14
BUILDLINK_ABI_DEPENDS.farsight2+=	farsight2>=0.0.26nb11
BUILDLINK_PKGSRCDIR.farsight2?=	../../multimedia/farsight2

# unsure which are needed exactly
#.include "../../devel/py-gobject/buildlink3.mk"
#.include "../../devel/glib2/buildlink3.mk"
#.include "../../multimedia/gst-plugins0.10-bad/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
#.include "../../multimedia/gst-plugins0.10-good/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
#.include "../../multimedia/py-gstreamer0.10/buildlink3.mk"
#.include "../../net/gupnp-igd/buildlink3.mk"
#.include "../../net/libnice/buildlink3.mk"
#.include "../../x11/py-gtk2/buildlink3.mk"
.endif	# FARSIGHT2_BUILDLINK3_MK

BUILDLINK_TREE+=	-farsight2
