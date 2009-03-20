# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 17:30:11 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PY_NUMPY_BUILDLINK3_MK:=	${PY_NUMPY_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	pynumpy
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npynumpy}
BUILDLINK_PACKAGES+=	pynumpy
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}pynumpy

.if ${PY_NUMPY_BUILDLINK3_MK} == "+"
.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0
BUILDLINK_PKGSRCDIR.pynumpy?=	../../math/py-numpy
.endif	# PY_NUMPY_BUILDLINK3_MK

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
