# $NetBSD: buildlink3.mk,v 1.33 2013/10/10 14:41:54 ryoon Exp $

BUILDLINK_TREE+=	wxsvg

.if !defined(WXSVG_BUILDLINK3_MK)
WXSVG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wxsvg+=	wxsvg>=1.0beta5
BUILDLINK_ABI_DEPENDS.wxsvg+=	wxsvg>=1.1.14nb5
BUILDLINK_PKGSRCDIR.wxsvg?=	../../graphics/wxsvg

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.endif # WXSVG_BUILDLINK3_MK

BUILDLINK_TREE+=	-wxsvg
