# $NetBSD: buildlink3.mk,v 1.1 2013/09/12 14:03:58 ryoon Exp $

BUILDLINK_TREE+=	cross-freemint-pml

.if !defined(CROSS_FREEMINT_PML_BUILDLINK3_MK)
CROSS_FREEMINT_PML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cross-freemint-pml+=	cross-freemint-pml>=2.03
BUILDLINK_PKGSRCDIR.cross-freemint-pml?=	../../cross/freemint-pml

.include "../../cross/freemint-mintlib/buildlink3.mk"
.endif	# CROSS_FREEMINT_PML_BUILDLINK3_MK

BUILDLINK_TREE+=	-cross-freemint-pml
