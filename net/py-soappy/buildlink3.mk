# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:25:11 joerg Exp $

BUILDLINK_TREE+=	py-SOAPpy

.if !defined(PY_SOAPPY_BUILDLINK3_MK)
PY_SOAPPY_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-SOAPpy+=	${PYPKGPREFIX}-SOAPpy>=0.11.4
BUILDLINK_ABI_DEPENDS.py-SOAPpy?=	${PYPKGPREFIX}-SOAPpy>=0.11.4nb4
BUILDLINK_PKGSRCDIR.py-SOAPpy?=	../../net/py-soappy

.include "../../textproc/py-xml/buildlink3.mk"
.endif # PY_SOAPPY_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-SOAPpy
