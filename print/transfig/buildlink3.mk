# $NetBSD: buildlink3.mk,v 1.5 2006/04/17 13:45:57 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
TRANSFIG_BUILDLINK3_MK:=	${TRANSFIG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	transfig
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntransfig}
BUILDLINK_PACKAGES+=	transfig

.if !empty(TRANSFIG_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.transfig+=	transfig>=3.2.4
BUILDLINK_ABI_DEPENDS.transfig?=	transfig>=3.2.5alpha7nb2
BUILDLINK_PKGSRCDIR.transfig?=	../../print/transfig
.endif	# TRANSFIG_BUILDLINK3_MK

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
