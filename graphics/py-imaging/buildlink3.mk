# $NetBSD: buildlink3.mk,v 1.4 2004/05/17 21:32:34 seb Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PY_IMAGING_BUILDLINK3_MK:=	${PY_IMAGING_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pyimaging
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npyimaging}
BUILDLINK_PACKAGES+=	pyimaging

.if !empty(PY_IMAGING_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.pyimaging+=	${PYPKGPREFIX}-imaging>=1.1.4
BUILDLINK_PKGSRCDIR.pyimaging?=	../../graphics/py-imaging
.endif	# PY_IMAGING_BUILDLINK3_MK

.include "../../graphics/jpeg/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
