# $NetBSD: buildlink3.mk,v 1.17 2020/02/13 08:35:18 adam Exp $

BUILDLINK_TREE+=	py-bsddb3

.if !defined(PY_BSDDB3_BUILDLINK3_MK)
PY_BSDDB3_BUILDLINK3_MK:=

.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-bsddb3+=	${PYPKGPREFIX}-bsddb3>=4.7.2
BUILDLINK_ABI_DEPENDS.py-bsddb3+=	${PYPKGPREFIX}-bsddb3>=4.7.2
BUILDLINK_PKGSRCDIR.py-bsddb3?=		../../databases/py-bsddb3

.include "../../mk/bdb.buildlink3.mk"
.endif # PY_BSDDB3_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-bsddb3
