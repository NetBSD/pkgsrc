# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:14:55 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBRSVG_BUILDLINK3_MK:=	${LIBRSVG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	librsvg
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibrsvg}
BUILDLINK_PACKAGES+=	librsvg

.if !empty(LIBRSVG_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.librsvg+=	librsvg>=1.0.1nb5
BUILDLINK_RECOMMENDED.librsvg+=	librsvg>=1.0.1nb7
BUILDLINK_PKGSRCDIR.librsvg?=	../../graphics/librsvg
.endif	# LIBRSVG_BUILDLINK3_MK

.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
