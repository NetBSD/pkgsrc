# $NetBSD: buildlink3.mk,v 1.15 2009/03/20 19:25:11 joerg Exp $

BUILDLINK_TREE+=	pyorbit

.if !defined(PY_ORBIT_BUILDLINK3_MK)
PY_ORBIT_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pyorbit+=	${PYPKGPREFIX}-ORBit>=2.0.0nb1
BUILDLINK_ABI_DEPENDS.pyorbit+=	${PYPKGPREFIX}-ORBit>=2.0.1nb1
BUILDLINK_PKGSRCDIR.pyorbit?=	../../net/py-ORBit

.include "../../net/ORBit2/buildlink3.mk"
.endif # PY_ORBIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-pyorbit
