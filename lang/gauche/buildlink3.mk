# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:10:54 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GAUCHE_BUILDLINK3_MK:=	${GAUCHE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	Gauche
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NGauche}
BUILDLINK_PACKAGES+=	Gauche
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}Gauche

.if !empty(GAUCHE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.Gauche+=	Gauche>=0.8.1
BUILDLINK_PKGSRCDIR.Gauche?=	../../lang/gauche
.endif	# GAUCHE_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
