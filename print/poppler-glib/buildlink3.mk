# $NetBSD: buildlink3.mk,v 1.21 2011/11/01 06:02:26 sbd Exp $

BUILDLINK_TREE+=	poppler-glib

.if !defined(POPPLER_GLIB_BUILDLINK3_MK)
POPPLER_GLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poppler-glib+=	poppler-glib>=0.5.1
BUILDLINK_ABI_DEPENDS.poppler-glib+=	poppler-glib>=0.16.7
BUILDLINK_PKGSRCDIR.poppler-glib?=	../../print/poppler-glib

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # POPPLER_GLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-poppler-glib
