# $NetBSD: buildlink3.mk,v 1.3 2004/11/26 09:39:30 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GAUCHE_BUILDLINK3_MK:=	${GAUCHE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	Gauche
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NGauche}
BUILDLINK_PACKAGES+=	Gauche

.if !empty(GAUCHE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.Gauche+=	Gauche>=0.8.1
BUILDLINK_PKGSRCDIR.Gauche?=	../../lang/gauche
.endif	# GAUCHE_BUILDLINK3_MK

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
