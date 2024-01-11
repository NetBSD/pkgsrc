# $NetBSD: buildlink3.mk,v 1.8 2024/01/11 11:29:47 jperkin Exp $

BUILDLINK_TREE+=	udunits

.if !defined(UDUNITS_BUILDLINK3_MK)
UDUNITS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.udunits+=	udunits>=2.2.26
BUILDLINK_PKGSRCDIR.udunits?=	../../math/udunits
.endif	# UDUNITS_BUILDLINK3_MK

.include "../../textproc/expat/buildlink3.mk"

BUILDLINK_TREE+=	-udunits
