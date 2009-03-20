# $NetBSD: buildlink3.mk,v 1.5 2009/03/20 19:25:22 joerg Exp $

BUILDLINK_TREE+=	py-amkCrypto

.if !defined(PY24_AMKCRYPTO_BUILDLINK3_MK)
PY24_AMKCRYPTO_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-amkCrypto+=	${PYPKGPREFIX}-amkCrypto>=2.0.1nb1
BUILDLINK_PKGSRCDIR.py-amkCrypto?=	../../security/py-amkCrypto
.endif # PY24_AMKCRYPTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-amkCrypto
