# $NetBSD: buildlink3.mk,v 1.29 2020/03/08 16:47:46 wiz Exp $

BUILDLINK_TREE+=	clutter-mx

.if !defined(CLUTTER_MX_BUILDLINK3_MK)
CLUTTER_MX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clutter-mx+=	clutter-mx>=1.0.3
BUILDLINK_ABI_DEPENDS.clutter-mx+=	clutter-mx>=1.0.4nb28
BUILDLINK_PKGSRCDIR.clutter-mx?=	../../graphics/clutter-mx

.include "../../graphics/clutter/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif	# CLUTTER_MX_BUILDLINK3_MK

BUILDLINK_TREE+=	-clutter-mx
