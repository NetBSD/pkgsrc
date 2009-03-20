# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 17:30:11 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PY_IMAGING_BUILDLINK3_MK:=	${PY_IMAGING_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pyimaging
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npyimaging}
BUILDLINK_PACKAGES+=	pyimaging
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}pyimaging

.if !empty(PY_IMAGING_BUILDLINK3_MK:M+)
.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pyimaging+=	${PYPKGPREFIX}-imaging>=1.1.4
BUILDLINK_ABI_DEPENDS.pyimaging?=	${PYPKGPREFIX}-imaging>=1.1.5nb1
BUILDLINK_PKGSRCDIR.pyimaging?=	../../graphics/py-imaging
.endif	# PY_IMAGING_BUILDLINK3_MK

.include "../../graphics/jpeg/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
