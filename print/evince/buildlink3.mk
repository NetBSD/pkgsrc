# $NetBSD: buildlink3.mk,v 1.1 2009/03/18 12:54:14 drochner Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EVINCE_BUILDLINK3_MK:=	${EVINCE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	evince
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nevince}
BUILDLINK_PACKAGES+=	evince
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}evince

.if ${EVINCE_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.evince+=	evince>=2.26.0
BUILDLINK_PKGSRCDIR.evince?=	../../print/evince
.endif	# EVINCE_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
