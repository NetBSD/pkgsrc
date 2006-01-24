# $NetBSD: buildlink3.mk,v 1.4 2006/01/24 07:32:35 wiz Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
NAUTILUS_CD_BURNER_BUILDLINK3_MK:=	${NAUTILUS_CD_BURNER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	nautilus-cd-burner
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nnautilus-cd-burner}
BUILDLINK_PACKAGES+=	nautilus-cd-burner

.if !empty(NAUTILUS_CD_BURNER_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.nautilus-cd-burner+=		nautilus-cd-burner>=2.12.1nb1
BUILDLINK_RECOMMENDED.nautilus-cd-burner?=	nautilus-cd-burner>=2.12.2nb1
BUILDLINK_PKGSRCDIR.nautilus-cd-burner?=	../../sysutils/nautilus-cd-burner
.endif	# NAUTILUS_CD_BURNER_BUILDLINK3_MK

.include "../../sysutils/nautilus/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
