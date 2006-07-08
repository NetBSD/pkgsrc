# $NetBSD: buildlink3.mk,v 1.11 2006/07/08 23:10:53 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
NETPBM_BUILDLINK3_MK:=	${NETPBM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	netpbm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nnetpbm}
BUILDLINK_PACKAGES+=	netpbm
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}netpbm

.if !empty(NETPBM_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.netpbm+=	netpbm>=10.11.6
BUILDLINK_ABI_DEPENDS.netpbm+=	netpbm>=10.33nb1
BUILDLINK_PKGSRCDIR.netpbm?=	../../graphics/netpbm
.endif	# NETPBM_BUILDLINK3_MK

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
