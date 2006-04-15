# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/04/15 18:25:07 minskim Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PY_CAIRO_BUILDLINK3_MK:=	${PY_CAIRO_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pycairo
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npycairo}
BUILDLINK_PACKAGES+=	pycairo

.if !empty(PY_CAIRO_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.pycairo+=	${PYPKGPREFIX}-cairo>=1.0.2
BUILDLINK_PKGSRCDIR.pycairo?=	../../graphics/py-cairo
.endif	# PY_CAIRO_BUILDLINK3_MK

.include "../../math/py-Numeric/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
