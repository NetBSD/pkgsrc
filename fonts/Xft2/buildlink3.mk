# $NetBSD: buildlink3.mk,v 1.2 2004/02/09 23:56:32 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XFT2_BUILDLINK3_MK:=	${XFT2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	Xft2
.endif

.if !empty(XFT2_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		Xft2
BUILDLINK_DEPENDS.Xft2+=	Xft2>=2.1.2nb1
BUILDLINK_PKGSRCDIR.Xft2?=	../../fonts/Xft2

BUILDLINK_DEPENDS.freetype2+=  freetype2>=2.0.9

.  include "../../devel/zlib/buildlink3.mk"
.  include "../../fonts/fontconfig/buildlink3.mk"
.  include "../../graphics/freetype2/buildlink3.mk"
.  include "../../x11/Xrender/buildlink3.mk"
.endif # XFT2_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
