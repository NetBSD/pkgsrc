# $NetBSD: buildlink3.mk,v 1.1 2004/01/22 11:02:01 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
NETPBM_BUILDLINK3_MK:=	${NETPBM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	netpbm
.endif

.if !empty(NETPBM_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		netpbm
BUILDLINK_DEPENDS.netpbm?=	netpbm>=10.11.6
BUILDLINK_PKGSRCDIR.netpbm?=	../../graphics/netpbm

.  include "../../graphics/png/buildlink3.mk"
.  include "../../graphics/tiff/buildlink3.mk"
.endif	# NETPBM_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
