# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/10/28 23:36:39 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
QOF_BUILDLINK3_MK:=	${QOF_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	qof
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nqof}
BUILDLINK_PACKAGES+=	qof
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}qof

.if ${QOF_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.qof+=	qof>=0.7.5
BUILDLINK_PKGSRCDIR.qof?=	../../devel/qof
.endif	# QOF_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
