# $NetBSD: buildlink3.mk,v 1.8 2006/12/15 20:33:00 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
TRANSFIG_BUILDLINK3_MK:=	${TRANSFIG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	transfig
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntransfig}
BUILDLINK_PACKAGES+=	transfig
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}transfig

.if !empty(TRANSFIG_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.transfig+=	transfig>=3.2.4
BUILDLINK_ABI_DEPENDS.transfig?=	transfig>=3.2.5alpha7nb2
BUILDLINK_PKGSRCDIR.transfig?=	../../print/transfig
.endif	# TRANSFIG_BUILDLINK3_MK

.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
