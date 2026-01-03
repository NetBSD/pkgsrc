# $NetBSD: buildlink3.mk,v 1.3 2026/01/03 11:57:44 wiz Exp $

BUILDLINK_TREE+=	QuantLib

.if !defined(QUANTLIB_BUILDLINK3_MK)
QUANTLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.QuantLib+=	QuantLib>=1.12.1
BUILDLINK_ABI_DEPENDS.QuantLib?=	QuantLib>=1.12.1nb16
BUILDLINK_PKGSRCDIR.QuantLib?=		../../finance/QuantLib

.include "../../devel/boost-headers/buildlink3.mk"
.endif	# QUANTLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-QuantLib
