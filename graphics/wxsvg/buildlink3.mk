# $NetBSD: buildlink3.mk,v 1.52 2023/01/29 21:14:46 ryoon Exp $

BUILDLINK_TREE+=	wxsvg

.if !defined(WXSVG_BUILDLINK3_MK)
WXSVG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wxsvg+=	wxsvg>=1.0beta5
BUILDLINK_ABI_DEPENDS.wxsvg+=	wxsvg>=1.5.22nb6
BUILDLINK_PKGSRCDIR.wxsvg?=	../../graphics/wxsvg

.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.endif # WXSVG_BUILDLINK3_MK

BUILDLINK_TREE+=	-wxsvg
