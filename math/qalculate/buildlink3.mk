# $NetBSD: buildlink3.mk,v 1.6 2006/04/06 06:22:22 reed Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
QALCULATE_BUILDLINK3_MK:=	${QALCULATE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	qalculate
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nqalculate}
BUILDLINK_PACKAGES+=	qalculate

.if !empty(QALCULATE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.qalculate+=	qalculate>=0.8.2
BUILDLINK_ABI_DEPENDS.qalculate?=	qalculate>=0.8.2nb2
BUILDLINK_PKGSRCDIR.qalculate?=	../../math/qalculate
.endif	# QALCULATE_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../math/cln/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
