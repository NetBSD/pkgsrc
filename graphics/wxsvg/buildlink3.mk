# $NetBSD: buildlink3.mk,v 1.50 2022/08/11 05:08:47 gutteridge Exp $

BUILDLINK_TREE+=	wxsvg

.if !defined(WXSVG_BUILDLINK3_MK)
WXSVG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wxsvg+=	wxsvg>=1.0beta5
BUILDLINK_ABI_DEPENDS.wxsvg+=	wxsvg>=1.5.22nb3
BUILDLINK_PKGSRCDIR.wxsvg?=	../../graphics/wxsvg

.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.endif # WXSVG_BUILDLINK3_MK

BUILDLINK_TREE+=	-wxsvg
