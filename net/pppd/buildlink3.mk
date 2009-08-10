# $NetBSD: buildlink3.mk,v 1.1 2009/08/10 14:03:56 dsainty Exp $

BUILDLINK_TREE+=	pppd

.if !defined(PPPD_BUILDLINK3_MK)
PPPD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pppd+=	pppd>=2.4.3nb2
BUILDLINK_PKGSRCDIR.pppd?=	../../net/pppd
.endif	# PPPD_BUILDLINK3_MK

BUILDLINK_TREE+=	-pppd
