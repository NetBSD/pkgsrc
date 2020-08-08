# $NetBSD: buildlink3.mk,v 1.7 2020/08/08 21:55:54 brook Exp $

BUILDLINK_TREE+=	udunits

.if !defined(UDUNITS_BUILDLINK3_MK)
UDUNITS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.udunits+=	udunits>=2.2.26
BUILDLINK_PKGSRCDIR.udunits?=	../../math/udunits
.endif	# UDUNITS_BUILDLINK3_MK

BUILDLINK_TREE+=	-udunits
