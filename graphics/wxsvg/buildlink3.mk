# $NetBSD: buildlink3.mk,v 1.45 2020/03/08 16:47:51 wiz Exp $

BUILDLINK_TREE+=	wxsvg

.if !defined(WXSVG_BUILDLINK3_MK)
WXSVG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wxsvg+=	wxsvg>=1.0beta5
BUILDLINK_ABI_DEPENDS.wxsvg+=	wxsvg>=1.5.20nb1
BUILDLINK_PKGSRCDIR.wxsvg?=	../../graphics/wxsvg

.include "../../graphics/libexif/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.endif # WXSVG_BUILDLINK3_MK

BUILDLINK_TREE+=	-wxsvg
