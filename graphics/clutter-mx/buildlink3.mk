# $NetBSD: buildlink3.mk,v 1.7 2012/05/07 01:53:32 dholland Exp $

BUILDLINK_TREE+=	clutter-mx

.if !defined(CLUTTER_MX_BUILDLINK3_MK)
CLUTTER_MX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clutter-mx+=	clutter-mx>=1.0.3
BUILDLINK_ABI_DEPENDS.clutter-mx+=	clutter-mx>=1.0.4nb5
BUILDLINK_PKGSRCDIR.clutter-mx?=	../../graphics/clutter-mx

.include "../../graphics/clutter/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif	# CLUTTER_MX_BUILDLINK3_MK

BUILDLINK_TREE+=	-clutter-mx
