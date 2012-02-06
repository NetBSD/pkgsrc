# $NetBSD: buildlink3.mk,v 1.17 2012/02/06 12:41:17 wiz Exp $

BUILDLINK_TREE+=	pyorbit

.if !defined(PY_ORBIT_BUILDLINK3_MK)
PY_ORBIT_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pyorbit+=	${PYPKGPREFIX}-ORBit>=2.0.0nb1
BUILDLINK_ABI_DEPENDS.pyorbit+=	${PYPKGPREFIX}-ORBit>=2.24.0nb2
BUILDLINK_PKGSRCDIR.pyorbit?=	../../net/py-ORBit

.include "../../net/ORBit2/buildlink3.mk"
.endif # PY_ORBIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-pyorbit
