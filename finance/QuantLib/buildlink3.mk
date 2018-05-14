# $NetBSD: buildlink3.mk,v 1.1 2018/05/14 00:06:44 minskim Exp $

BUILDLINK_TREE+=	QuantLib

.if !defined(QUANTLIB_BUILDLINK3_MK)
QUANTLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.QuantLib+=	QuantLib>=1.12.1
BUILDLINK_PKGSRCDIR.QuantLib?=		../../finance/QuantLib

.include "../../devel/boost-headers/buildlink3.mk"
.endif	# QUANTLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-QuantLib
