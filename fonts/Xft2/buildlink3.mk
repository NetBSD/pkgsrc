# $NetBSD: buildlink3.mk,v 1.11 2004/03/10 17:57:14 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XFT2_BUILDLINK3_MK:=	${XFT2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=		Xft2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NXft2}
BUILDLINK_PACKAGES+=	Xft2

.if !empty(XFT2_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.Xft2+=	Xft2>=2.1
BUILDLINK_PKGSRCDIR.Xft2?=	../../fonts/Xft2

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"

.endif	# XFT2_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
