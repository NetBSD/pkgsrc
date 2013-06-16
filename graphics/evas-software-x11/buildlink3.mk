# $NetBSD: buildlink3.mk,v 1.6 2013/06/16 18:56:05 sno Exp $

BUILDLINK_TREE+=	evas-software-x11

.if !defined(EVAS_SOFTWARE_X11_BUILDLINK3_MK)
EVAS_SOFTWARE_X11_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evas-software-x11+=	evas-software-x11>=1.7.0alpha
BUILDLINK_PKGSRCDIR.evas-software-x11?=	../../graphics/evas-software-x11

.include "../../x11/libX11/buildlink3.mk"
.endif # EVAS_SOFTWARE_X11_BUILDLINK3_MK

BUILDLINK_TREE+=	-evas-software-x11
