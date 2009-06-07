# $NetBSD: buildlink3.mk,v 1.1 2009/06/07 21:12:13 joerg Exp $

BUILDLINK_TREE+=	evas-xrender-x11

.if !defined(EVAS_XRENDER_X11_BUILDLINK3_MK)
EVAS_XRENDER_X11_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evas-xrender-x11+=	evas-xrender-x11>=0.9.9.060
BUILDLINK_PKGSRCDIR.evas-xrender-x11?=	../../graphics/evas-xrender-x11
.endif	# EVAS_XRENDER_X11_BUILDLINK3_MK

BUILDLINK_TREE+=	-evas-xrender-x11
