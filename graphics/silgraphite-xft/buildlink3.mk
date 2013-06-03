# $NetBSD: buildlink3.mk,v 1.6 2013/06/03 10:05:21 wiz Exp $

BUILDLINK_TREE+=	silgraphite-xft

.if !defined(SILGRAPHITE_XFT_BUILDLINK3_MK)
SILGRAPHITE_XFT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.silgraphite-xft+=	silgraphite-xft>=2.3
BUILDLINK_ABI_DEPENDS.silgraphite-xft+=	silgraphite-xft>=2.3.1nb2
BUILDLINK_PKGSRCDIR.silgraphite-xft?=	../../graphics/silgraphite-xft

.include "../../graphics/silgraphite-ft/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.endif # SILGRAPHITE_XFT_BUILDLINK3_MK

BUILDLINK_TREE+=	-silgraphite-xft
