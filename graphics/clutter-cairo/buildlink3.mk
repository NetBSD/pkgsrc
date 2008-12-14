# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/12/14 11:04:35 obache Exp $
#

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
CLUTTER_CAIRO_BUILDLINK3_MK:=	${CLUTTER_CAIRO_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	clutter-cairo
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nclutter-cairo}
BUILDLINK_PACKAGES+=	clutter-cairo
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}clutter-cairo

.if ${CLUTTER_CAIRO_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.clutter-cairo+=	clutter-cairo>=0.8.0
BUILDLINK_PKGSRCDIR.clutter-cairo?=	../../graphics/clutter-cairo
.endif	# CLUTTER_CAIRO_BUILDLINK3_MK

.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/clutter/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
