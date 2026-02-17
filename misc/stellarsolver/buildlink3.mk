# $NetBSD: buildlink3.mk,v 1.1 2026/02/17 18:41:01 markd Exp $

BUILDLINK_TREE+=	stellarsolver

.if !defined(STELLARSOLVER_BUILDLINK3_MK)
STELLARSOLVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.stellarsolver+=	stellarsolver>=2.5
BUILDLINK_PKGSRCDIR.stellarsolver?=	../../misc/stellarsolver

.include "../../devel/cfitsio/buildlink3.mk"
.include "../../graphics/wcslib/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.endif	# STELLARSOLVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-stellarsolver
