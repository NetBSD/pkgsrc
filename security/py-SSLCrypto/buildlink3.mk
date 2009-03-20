# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:25:22 joerg Exp $

BUILDLINK_TREE+=	py-SSLCrypto

.if !defined(PY_SSLCRYPTO_BUILDLINK3_MK)
PY_SSLCRYPTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-SSLCrypto+=	${PYPKGPREFIX}-SSLCrypto>=0.1.1
BUILDLINK_ABI_DEPENDS.py-SSLCrypto?=	${PYPKGPREFIX}-SSLCrypto>=0.1.1nb1
BUILDLINK_PKGSRCDIR.py-SSLCrypto?=	../../security/py-SSLCrypto

#.include "../../security/openssl/buildlink3.mk"
.endif # PY_SSLCRYPTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-SSLCrypto
