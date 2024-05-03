# $NetBSD: buildlink3.mk,v 1.1 2024/05/03 11:17:14 wiz Exp $

BUILDLINK_TREE+=	indi

.if !defined(INDI_BUILDLINK3_MK)
INDI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.indi+=	indi>=2.0.7
BUILDLINK_PKGSRCDIR.indi?=	../../misc/indi

.include "../../devel/cfitsio/buildlink3.mk"
.include "../../geography/libnova/buildlink3.mk"
.endif	# INDI_BUILDLINK3_MK

BUILDLINK_TREE+=	-indi
