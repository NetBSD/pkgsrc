# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/01/24 03:42:28 xtraeme Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
WXSVG_BUILDLINK3_MK:=	${WXSVG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	wxsvg
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nwxsvg}
BUILDLINK_PACKAGES+=	wxsvg

.if !empty(WXSVG_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.wxsvg+=	wxsvg>=1.0beta5
BUILDLINK_PKGSRCDIR.wxsvg?=	../../graphics/wxsvg
.endif	# WXSVG_BUILDLINK3_MK

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
