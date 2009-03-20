# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:24:59 joerg Exp $

BUILDLINK_TREE+=	udunits

.if !defined(UDUNITS_BUILDLINK3_MK)
UDUNITS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.udunits+=	udunits>=1.11.7
BUILDLINK_PKGSRCDIR.udunits?=	../../math/udunits
BUILDLINK_DEPMETHOD.udunits?=	build
BUILDLINK_FILES.udunits=	include/udunits.inc
.endif # UDUNITS_BUILDLINK3_MK

BUILDLINK_TREE+=	-udunits
