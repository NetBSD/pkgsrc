# $NetBSD: buildlink3.mk,v 1.5.4.1 2005/08/07 05:03:33 snj Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
NETPBM_BUILDLINK3_MK:=	${NETPBM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	netpbm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nnetpbm}
BUILDLINK_PACKAGES+=	netpbm

.if !empty(NETPBM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.netpbm+=	netpbm>=10.11.6
BUILDLINK_RECOMMENDED.netpbm+=	netpbm>=10.28
BUILDLINK_PKGSRCDIR.netpbm?=	../../graphics/netpbm
.endif	# NETPBM_BUILDLINK3_MK

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
