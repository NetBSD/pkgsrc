# $NetBSD: buildlink3.mk,v 1.17 2008/12/07 15:16:53 wiz Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
NAUTILUS_CD_BURNER_BUILDLINK3_MK:=	${NAUTILUS_CD_BURNER_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	nautilus-cd-burner
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nnautilus-cd-burner}
BUILDLINK_PACKAGES+=	nautilus-cd-burner
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}nautilus-cd-burner

.if ${NAUTILUS_CD_BURNER_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.nautilus-cd-burner+=	nautilus-cd-burner>=2.24.0
BUILDLINK_PKGSRCDIR.nautilus-cd-burner?=	../../sysutils/nautilus-cd-burner
.endif	# NAUTILUS_CD_BURNER_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/hal/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
