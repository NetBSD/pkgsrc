# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/03/02 16:46:01 manu Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LASSO_BUILDLINK3_MK:=	${LASSO_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	lasso
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlasso}
BUILDLINK_PACKAGES+=	lasso
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}lasso

.if ${LASSO_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.lasso+=	lasso>=2.2.1
BUILDLINK_PKGSRCDIR.lasso?=	../../security/lasso
.endif	# LASSO_BUILDLINK3_MK

.include "../../security/xmlsec1/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
