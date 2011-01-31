# $NetBSD: buildlink3.mk,v 1.18 2011/01/31 16:58:42 drochner Exp $

BUILDLINK_TREE+=	poppler-glib

.if !defined(POPPLER_GLIB_BUILDLINK3_MK)
POPPLER_GLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poppler-glib+=	poppler-glib>=0.5.1
BUILDLINK_ABI_DEPENDS.poppler-glib+=	poppler-glib>=0.16.2
BUILDLINK_PKGSRCDIR.poppler-glib?=	../../print/poppler-glib

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # POPPLER_GLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-poppler-glib
