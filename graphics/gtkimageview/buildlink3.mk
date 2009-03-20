# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:40 joerg Exp $

BUILDLINK_TREE+=	gtkimageview

.if !defined(GTKIMAGEVIEW_BUILDLINK3_MK)
GTKIMAGEVIEW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtkimageview+=	gtkimageview>=1.3.0
BUILDLINK_PKGSRCDIR.gtkimageview?=	../../graphics/gtkimageview
.endif # GTKIMAGEVIEW_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkimageview
