# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/10/22 10:27:17 obache Exp $
#

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GOOCANVAS_BUILDLINK3_MK:=	${GOOCANVAS_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	goocanvas
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngoocanvas}
BUILDLINK_PACKAGES+=	goocanvas
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}goocanvas

.if ${GOOCANVAS_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.goocanvas+=	goocanvas>=0.12
BUILDLINK_PKGSRCDIR.goocanvas?=	../../graphics/goocanvas
.endif	# GOOCANVAS_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
