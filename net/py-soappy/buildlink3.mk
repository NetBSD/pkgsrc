# $NetBSD: buildlink3.mk,v 1.1 2004/08/13 08:57:14 recht Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PY_SOAPPY_BUILDLINK3_MK:=	${PY_SOAPPY_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	py-SOAPpy
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npy-SOAPpy}
BUILDLINK_PACKAGES+=	py-SOAPpy

.if !empty(PY_SOAPPY_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.py-SOAPpy+=	${PYPKGPREFIX}-SOAPpy>=0.11.4
BUILDLINK_PKGSRCDIR.py-SOAPpy?=	../../net/py-soappy
.endif	# PY_SOAPPY_BUILDLINK3_MK

.include "../../textproc/py-xml/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
