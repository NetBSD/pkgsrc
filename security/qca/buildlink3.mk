# $NetBSD: buildlink3.mk,v 1.2 2006/01/24 07:32:33 wiz Exp $
# 
BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
QCA_BUILDLINK3_MK:=	${QCA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	qca
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nqca}
BUILDLINK_PACKAGES+=	qca

.if !empty(QCA_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.qca+=	qca>=1.0
BUILDLINK_RECOMMENDED.qca?=	qca>=1.0nb1
BUILDLINK_PKGSRCDIR.qca?=	../../security/qca
.endif	# QCA_BUILDLINK3_MK

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
