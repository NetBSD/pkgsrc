# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/05/12 12:40:32 jmcneill Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
COMPIZ_BCOP_BUILDLINK3_MK:=	${COMPIZ_BCOP_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	compiz-bcop
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ncompiz-bcop}
BUILDLINK_PACKAGES+=	compiz-bcop
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}compiz-bcop

.if ${COMPIZ_BCOP_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.compiz-bcop+=	compiz-bcop>=0.6.0
BUILDLINK_PKGSRCDIR.compiz-bcop?=	../../devel/compiz-bcop
.endif	# COMPIZ_BCOP_BUILDLINK3_MK

.include "../../wm/compiz/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
