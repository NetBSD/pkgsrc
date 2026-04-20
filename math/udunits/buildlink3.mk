# $NetBSD: buildlink3.mk,v 1.9 2026/04/20 05:57:14 wiz Exp $

BUILDLINK_TREE+=	udunits

.if !defined(UDUNITS_BUILDLINK3_MK)
UDUNITS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.udunits+=	udunits>=2.2.26
BUILDLINK_PKGSRCDIR.udunits?=	../../math/udunits
.include "../../textproc/expat/buildlink3.mk"
.endif	# UDUNITS_BUILDLINK3_MK

BUILDLINK_TREE+=	-udunits
