# $NetBSD: buildlink3.mk,v 1.21 2025/10/23 20:38:53 wiz Exp $

BUILDLINK_TREE+=	pyorbit

.if !defined(PY_ORBIT_BUILDLINK3_MK)
PY_ORBIT_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pyorbit+=	${PYPKGPREFIX}-ORBit>=2.0.0nb1
BUILDLINK_ABI_DEPENDS.pyorbit+=	${PYPKGPREFIX}-ORBit>=2.24.0nb8
BUILDLINK_PKGSRCDIR.pyorbit?=	../../net/py-ORBit

.include "../../net/ORBit2/buildlink3.mk"
.endif # PY_ORBIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-pyorbit
