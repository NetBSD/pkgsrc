# $NetBSD: buildlink3.mk,v 1.7 2004/10/03 00:13:32 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PANGO_BUILDLINK3_MK:=	${PANGO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pango
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npango}
BUILDLINK_PACKAGES+=	pango

.if !empty(PANGO_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.pango+=	pango>=1.6.0
BUILDLINK_RECOMMENDED.pango+=	pango>=1.6.0nb1
BUILDLINK_PKGSRCDIR.pango?=	../../devel/pango
.endif	# PANGO_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
