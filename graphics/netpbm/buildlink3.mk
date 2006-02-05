# $NetBSD: buildlink3.mk,v 1.7 2006/02/05 23:09:36 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
NETPBM_BUILDLINK3_MK:=	${NETPBM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	netpbm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nnetpbm}
BUILDLINK_PACKAGES+=	netpbm

.if !empty(NETPBM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.netpbm+=	netpbm>=10.11.6
BUILDLINK_RECOMMENDED.netpbm+=	netpbm>=10.31nb2
BUILDLINK_PKGSRCDIR.netpbm?=	../../graphics/netpbm
.endif	# NETPBM_BUILDLINK3_MK

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
