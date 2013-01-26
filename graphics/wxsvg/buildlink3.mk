# $NetBSD: buildlink3.mk,v 1.27 2013/01/26 21:36:33 adam Exp $

BUILDLINK_TREE+=	wxsvg

.if !defined(WXSVG_BUILDLINK3_MK)
WXSVG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wxsvg+=	wxsvg>=1.0beta5
BUILDLINK_ABI_DEPENDS.wxsvg+=	wxsvg>=1.1.9nb1
BUILDLINK_PKGSRCDIR.wxsvg?=	../../graphics/wxsvg

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.endif # WXSVG_BUILDLINK3_MK

BUILDLINK_TREE+=	-wxsvg
